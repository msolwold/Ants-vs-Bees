/**
 * Board class
 * 
 * Holds the board object and the methods used to access it
 * 
 */

#include <string>
#include <iostream>

#include "Board.h"

using namespace std;

Board::Board()
{

    board_size = 10;
    create_board();

    total_num_ants = 0;
    total_num_bees = 0;

    queen_alive = true;
}

// * Helpers

/**
 * Creates the board object
 * 
 * Creates an Array of size board_size and populates it with Square structs
 */
void Board::create_board()
{
    cout << "Creating Board...\n\n";

    board = new Square[board_size];

    for (int i = 0; i < board_size; i++)
    {
        board[i].isBodyguard = false;
        board[i].isAnt = false;
        board[i].isNinja = false;
        board[i].isBlocked = false;

        board[i].num_ants = 0;
        board[i].num_bees = 0;
    }
}

// * Accessors

/**
 * Returns the size of the playing board
 * 
 * @return int
 */
int Board::get_board_size() const
{
    return board_size;
}

/**
 * Returns the board object
 * 
 * @return Square *
 */
Board::Square * Board::get_board() const
{
    return board;
}

/**
 * Returns the total number of ants on the board
 * 
 * @return int
 */
int Board::get_total_num_ants() const
{
    return total_num_ants;
}

/**
 * Returns the total number of bees on the board
 * 
 * @return int
 */
int Board::get_total_num_bees() const
{
    return total_num_bees;
}

/**
 * Returns the number of harvesters currently active on the board
 * 
 * @return int
 */
int Board::get_total_num_harvesters() const
{
    return total_num_harvesters;
}

/**
 * Returns true if there is a Bodyguard at the given index
 * 
 * @param int index
 * 
 * @return bool
 */
bool Board::isBodyguard(int index) const
{
    return board[index].isBodyguard;
}

/**
 * Returns true if there is an Ant at the given index
 * 
 * Ant: A non Bodyguard Ant
 * 
 * @param int index
 * 
 * @return bool
 */
bool Board::isAnt(int index) const
{
    return board[index].isAnt;
}

/**
 * Returns true if there is a Ninja at the given index
 * 
 * @param int index
 * 
 * @return bool
 */
bool Board::isNinja(int index) const
{
    return board[index].isNinja;
}

/**
 * Returns true if the square has an Ant that blocks the bees from moving through
 * 
 * @param int index
 * 
 * @return bool
 */
bool Board::isBlocked(int index) const
{
    return board[index].isBlocked;
}

/**
 * Returns the number of Ants at a given index
 * 
 * @param int index
 * 
 * @return int
 */
int Board::get_num_ants(int index) const
{
    return board[index].num_ants;
}

/**
 * Returns the number of Bees at a given index
 * 
 * @param int index of the square
 * 
 * @return int index
 */
int Board::get_num_bees(int index) const
{
    return board[index].num_bees;
}

/**
 * Returns true if the Queen Bee is still alive
 * 
 * @return bool
 */
bool Board::queen_isAlive() const
{
    return queen_alive;
}

/**
 * 
 * Returns true if the ant can be placed at the given location
 * 
 * @param int index
 * @param Ant * ant
 * 
 * @return bool
 */
bool Board::can_place_ant(int index, const Ant *a) const
{
    if (a->get_ant_type() == "Bodyguard"){ 
        if (board[index].isBodyguard)
        {
            cout << "You cannot place another Bodyguard in this position!" << endl;
            return false;
        }

        return true;
    }

    else if (board[index].isAnt)
    {
        cout << "There is already an ant at this position!" << endl;
        return false;
    }

    return true;
}

/**
 * 
 * Returns true if the bee can move forward
 * 
 * Will check the square is "blocked" (Has an ant that stops bee movement)
 * Will also check if the bee has already attacked this round
 * 
 * Returns false if either condition is true
 * 
 * @param int index 
 * @param Bee * bee
 * 
 * @return bool
 */
bool Board::can_move_bee(int index, const Bee *b) const
{
    return !board[index].isBlocked && !b->hasAttacked();
}

/**
 * Iterates over all ants on the board. Calls the attack method of the ant if
 * it is an attacker (Thrower)
 * 
 * Returns true if all bees are killed after this function runs
 * 
 * @return bool
 */
bool Board::ants_attack()
{

    for (int i = 0; i < board_size; i++)
    {
        vector<Ant*> ants = board[i].ants;

        for (int j = 0; j < ants.size(); j++)
        {
            if (ants[j]->isAttacker())
                ants[j]->attack(this);

            if (total_num_bees < 1) return true;
        }
    }
    return false;
}

/**
 * Spawns a Bee on the board
 */
void Board::spawn_bee()
{
    add_bee(board_size-1, new Bee());
}

/**
 * Handles the two actions the Bee can have
 * 
 * First tries to move and win the game
 * If it cannot move forward, it tries to attack the ant in the space
 * 
 * Returns true if a Bee successfully moves to the Queen (Index -1)
 * 
 * @return bool
 */
bool Board::bees_action()
{
    for (int i = 0; i < board_size; i++)
    {
        for(vector<Bee*>::iterator bee_it = board[i].bees.begin(); bee_it != board[i].bees.end() && board[i].bees.size() > 0; )
        {
            if (can_move_bee(i, *bee_it))
            {
                cout << "moving bee forward" << endl;
                if (move_bee(i, bee_it))            // Move the bee if it is not blocked
                    return true;
                
                bee_it = board[i].bees.erase(bee_it);
            }
            else if (!(*bee_it)->hasAttacked()) {
                bee_attack(i, *bee_it);
                 ++bee_it;
            }
        }
    }
    return false;
}

/**
 * Triggers the bee to attack. 
 * 
 * First checks to see if a Bodyguard is in the square
 * Then looks for a non ninja ant to attack
 * If the bee kills a fire ant, all bees in that square are killed
 * 
 * @param int board_index 
 * @param Bee * bee
 */
void Board::bee_attack(int board_index, Bee * b)
{
    cout << "Bee is attacking" << endl;
    b->attack();

    if (board[board_index].isBodyguard)
    { 
        if (board[board_index].Bodyguard->damage())        // Attack the Bodyguard
        { 
            remove_ant(board_index, board[board_index].ants.begin());
            board[board_index].ants.erase(board[board_index].ants.begin());
        }
    }
                
    else
    {
        vector<Ant*>::iterator ant_it = board[board_index].ants.begin();

        while (ant_it != board[board_index].ants.end())
        {
            cout << "Bee is attacking a " << (*ant_it)->get_ant_type() << " ant" << endl;

            if ((*ant_it)->get_ant_type() != "Ninja" && (*ant_it)->damage())
            {
                if ((*ant_it)->get_ant_type() == "Fire") kill_all_bees(board_index);
                remove_ant(board_index, ant_it);
                ant_it = board[board_index].ants.erase(ant_it);
            }
            else ant_it++;
        }
    }
    refresh_square(board_index);
}

// * Mutators

void Board::refresh_square(int index)
{
    board[index].isBlocked = false;

    vector<Ant*> * ants = &board[index].ants;

    for (vector<Ant*>::iterator it = (*ants).begin(); it != (*ants).end(); ++it)
    {
        if ((*it)->isBlocking()) board[index].isBlocked = true;
    }
}

/**
 * Refreshes all Bees and Ants currently on the board
 * 
 * Returns the total number of resources gained from Harvesters
 * 
 * @return int
 */
int Board::refresh_board()
{
    int num_resources = 0;

    for (int i = 0; i < board_size; i++)
    {
        board[i].isBlocked = false;

        vector<Ant*> * ants = &board[i].ants;
        vector<Bee*> * bees = &board[i].bees;

        for (vector<Ant*>::iterator it = (*ants).begin(); it != (*ants).end(); ++it)
        {
            (*it)->refresh_ant();
            if ((*it)->isBlocking()) board[i].isBlocked = true;
            if ((*it)->get_ant_type() == "Harvester")
                num_resources++;
        }

        for (vector<Bee*>::iterator it = (*bees).begin(); it != (*bees).end(); ++it)
        {
            (*it)->refresh_bee();
        }
    }
    return num_resources;
}

/**
 * Place an ant on the board at a given location
 * 
 * @param int index
 * @param Ant * a ant
 */
void Board::place_ant(int index, Ant *a)
{
    board[index].isBlocked = true;

    if (a->get_ant_type() == "Bodyguard")
    {
        vector<Ant*>::iterator it = board[index].ants.begin();
        board[index].ants.insert(it, a);

        board[index].isBodyguard = true;
        board[index].Bodyguard = a;
    }

    else 
    {
        board[index].isAnt = true;
        board[index].ants.push_back(a);

        if (a->get_ant_type() == "Ninja")
        {
            board[index].isNinja = true;
            board[index].isBlocked = false;
        }

        else if (a->get_ant_type() == "Harvester")
            total_num_harvesters++;
    }

    total_num_ants++;
    board[index].num_ants++;
    a->set_ant_position(index);
}

/**
 * Deletes the ant at the given location on the board
 * 
 * @param int board_index 
 * @param vector<Ant*>::iterator
 */
void Board::remove_ant(int board_index, vector<Ant*>::iterator it)
{
    Ant * a = *it;

    cout << a->get_ant_type() << " has been killed" << endl;

    if (a->get_ant_type() == "Bodyguard")
        board[board_index].isBodyguard = false;
    else
        if (a->get_ant_type() == "Harvester")
            total_num_harvesters--;
        board[board_index].isAnt = false;
    
    board[board_index].num_ants--;
}

/**
 * Kills a given bee
 * Called exclusively by Throwers
 * 
 * @param int board_index
 * @param Bee * b bee
 */
void Board::kill_bee(int board_index, Bee * b)
{
    cout << "A bee in square " << board_index << " has been killed!" << endl;

    remove_bee(board_index, board[board_index].bees.begin());
    board[board_index].bees.erase(board[board_index].bees.begin());
}

/**
 * Kills all the bees in a given square (Death of a fire ant)
 * 
 * @param int board_index
 */
void Board::kill_all_bees(int board_index)
{
    while (board[board_index].bees.size() > 0)
    {
        remove_bee(board_index, board[board_index].bees.begin());
        board[board_index].bees.erase(board[board_index].bees.begin());
    }
}

/**
 * Moves the bee forward one space
 * 
 * Returns true if a Bee successfully moves to the Queen (Index -1)
 * 
 * @param int board_index
 * @param vector<Bee*>::iterator
 * 
 * @return bool
 */
bool Board::move_bee(int board_index, vector<Bee*>::iterator it)
{
    if (board_index == 0)
    { 
        queen_alive = false;
        return true;
    }
    Bee * b = *it;

    remove_bee(board_index, it);
    
    if (board[board_index].isNinja && b->damage())  // if there is a ninja and the bee dies, dont add it to next position
        return false;

    add_bee(board_index-1, b);

    return false;
}

/**
 * Deletes the bee at the given index of a square
 * 
 * @param int board_index
 * @param vector<Bee*> iterator
 */
void Board::remove_bee(int board_index, vector<Bee*>::iterator it)
{
    board[board_index].num_bees--;
    total_num_bees--;
}

/**
 * Adds a bee in the square of the given index
 * 
 * @param int board_index index on the board
 * @param Bee * b bee that is being added
 */
void Board::add_bee(int board_index, Bee * b)
{
    board[board_index].bees.push_back(b);

    board[board_index].num_bees++;
    total_num_bees++;

    b->set_bee_position(board_index);
}

// * Helpers

void Board::print_board() const // ! NO
{
    string box = "";
    string border = print_border();

    box += border;

    for (int i = 0; i < 3; i++)
    {
        for (int index = 0; index < board_size; index++)
        {
            box += print_inner_square(index, i);
        }
        box += "*\n";
    }

    box += border;

    cout << box << endl << endl;
}

/**
 * Returns a string representing the ants in a space
 * 
 * @param vector<Ant*>::iterator - end of the list of ants
 * @param vector<Ant*>::iterator - beginning of the list of ants
 * 
 * @return string
 */
string Board::print_ants(vector<Ant*>::iterator ant_it, vector<Ant*>::iterator beginning) const
{
    string ants = "";
    while (ant_it != beginning)
    {
        ant_it--;
        ants += " ";
        ants += (*ant_it)->get_ant_initials();
        ants += "(";
        ants += to_string((*ant_it)->get_ant_health());
        ants += ")";
        ants += " ";
    }
    return ants;
}

/**
 * Returns a string representing the bees in a space
 * 
 * @param vector<Ant*>::iterator - beginning of the list of bees
 * 
 * @return string
 */
string Board::print_bees(vector<Bee*>::iterator bee_it, vector<Bee*>::iterator end) const
{
    string bees = "";
    while (bee_it != end)
    {
        bees += " b";
        bees += "(";
        bees += to_string((*bee_it)->get_bee_health());
        bees += ")";
        bees += " ";
        bee_it++;
    }
    return bees;
}

/**
 * Returns a string representing the inside of the square
 * 
 * @param int index
 * 
 * @return string
 */
string Board::print_inner_square(int index, int i) const
{
    string inner = "";

    Square currSq = board[index];

    int num_ants = currSq.num_ants;
    int num_bees = currSq.num_bees;

    int columns = (num_ants)*2 + (num_bees)*2 + 1;

    vector<Ant*>::iterator ant_it = currSq.ants.end();
    vector<Bee*>::iterator bee_it = currSq.bees.begin();

    inner += "* ";
    if (i == 1)
    {
        inner += print_ants(ant_it, currSq.ants.begin());

        for (int k = 0; k < (columns - ((num_bees*2)+(num_ants*2))); k++) inner += " ";
        inner += "  ";
        for (int k = 0; k < (columns - ((num_bees*2)+(num_ants*2))); k++) inner += " ";

        inner += print_bees(bee_it, currSq.bees.end());
    }

    else
    {
        for (int i = 0; i < columns; i++)
        {
            inner += "   ";
        }
        inner += " ";
    }
    return inner;
}

/**
 * Returns a string representing top and bottom borders
 * 
 * @return string
 */
string Board::print_border() const
{
    string border = "";
    for (int index = 0; index < board_size; index++)
    {
        Square currSq = board[index];

        int num_ants = currSq.num_ants;
        int num_bees = currSq.num_bees;

        int columns = (num_ants)*2 + (num_bees)*2 + 1;

        border += "* ";

        for (int i = 0; i < columns; i++)
        {
            border += " * ";
        }
        border += " ";
    }
    border += "*\n";

    return border;
}

Board::~Board()
{
    delete[] board;
}