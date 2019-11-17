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

// TODO - Implement destructor
Board::~Board()
{
    // delete
}

// * Helpers

void Board::create_board()
{
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

int Board::get_board_size() const
{
    return board_size;
}

Board::Square * Board::get_board() const
{
    return board;
}

int Board::get_total_num_ants()
{
    return total_num_ants;
}

int Board::get_total_num_bees()
{
    return total_num_bees;
}

bool Board::isBodyguard(int index) const
{
    return board[index].isBodyguard;
}

bool Board::isAnt(int index) const
{
    return board[index].isAnt;
}

bool Board::isNinja(int index) const
{
    return board[index].isNinja;
}

bool Board::isBlocked(int index) const
{
    return board[index].isBlocked;
}

int Board::get_num_ants(int index) const
{
    return board[index].num_ants;
}

int Board::get_num_bees(int index) const
{
    return board[index].num_bees;
}

bool Board::queen_isAlive() const
{
    return queen_alive;
}

/**
 * 
 * Returns true if the ant can be placed at the given location
 * 
 * @param int selection index on the board
 * @param Ant * ant being placed
 */
bool Board::can_place_ant(int index, const Ant *a) const
{

    if (a->get_ant_type() == "Bodyguard" && board[index].isBodyguard)
    {

        cout << "You cannot place another Bodyguard in this position!" << endl;
        return false;
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
 * @param int index index on the board
 * @param Bee * b bee being placed
 */
bool Board::can_move_bee(int index, const Bee *b) const
{
    return !board[index].isBlocked && !b->hasAttacked;
}

/**
 * Iterates over all ants on the board. Calls the attack method of the ant if
 * it is an attacker (Thrower)
 * 
 * @return bool true if there are no bees remaining on the board
 */
bool Board::ants_attack()
{
    for (int i = 0; i < board_size; i++)
    {
        vector<Ant*> ants = board[i].ants;

        for (int j = 0; j < ants.size; j++)
        {
            if (ants[j]->isAttacker())
                ants[j]->attack(this);

            if (total_num_bees < 1) return true;
        }
    }
    return false;
}

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
 * @return bool true is a bee gets to the Queen
 */
bool Board::bees_action()
{
    for (int i = 0; i < board_size; i++)
    {
        vector<Bee*> bees = board[i].bees;

        for(vector<Bee*>::iterator bee_it = bees.begin(); bee_it != bees.end();)
        {
            if (can_move_bee(i, *bee_it) && move_bee(i, bee_it))            // Move the bee if it is not blocked
                return true;

            else bee_attack(i, *bee_it);
        }
    }
}

/**
 * Triggers the bee to attack. First checks to see if a Bodyguard is in the square
 * Then looks for a non ninja ant to attack
 * If the bee kills a fire ant, all bees in that square are killed
 * 
 * @param int board_index index of the square
 * @param Bee * b Bee that is currently attacking
 */
void Board::bee_attack(int board_index, Bee * b)
{
    b->attack();

    if (board[board_index].isBodyguard && board[board_index].Bodyguard->damage())       // Attack the Bodyguard
        remove_ant(board_index, board[board_index].ants.begin());
                
    else
    {
        vector<Ant*>::iterator ant_it = board[board_index].ants.begin();

        while (ant_it != board[board_index].ants.end())
        {
            if ((*ant_it)->get_ant_type() != "Ninja" && (*ant_it)->damage())
            {
                if ((*ant_it)->get_ant_type() == "Fire") kill_all_bees(board_index);
                remove_ant(board_index, ant_it);
            }
        }
    }
}

// * Mutators

/**
 * Place an ant on the board at a given location
 * 
 * @param int index location on the board
 * @param Ant * a ant to be placed
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
    }

    total_num_ants++;
    board[index].num_ants++;
    a->set_ant_position(index);
}

/**
 * Deletes the ant at the given location on the board
 * 
 * @param int board_index Location of the ant on the board
 * @param vector<Ant*>::iterator iterator that points at the ant
 */
void Board::remove_ant(int board_index, vector<Ant*>::iterator it)
{
    Ant * a = *it;

    if (a->get_ant_type() == "Bodyguard")
        board[board_index].isBodyguard = false;
    else
        board[board_index].isAnt = false;
    
    board[board_index].num_ants--;
    board[board_index].ants.erase(it);
    delete[] a;
}

/**
 * Kills a given bee
 * Called exclusively by Throwers
 * 
 * @param int board_index Location on the board of the bee (Assumed the first bee in a square)
 * @param Bee * b bee to be killed
 */
void Board::kill_bee(int board_index, Bee * b)
{
    cout << "A bee in square " << board_index << " has been killed!" << endl;

    remove_bee(board_index, board[board_index].bees.begin());
    delete[] b;
}

/**
 * Kills all the bees in a given square (Death of a fire ant)
 * 
 * @param int board_index position where fire ant was killed
 */
void Board::kill_all_bees(int board_index)
{
    while (board[board_index].bees.size > 0)
    {
        Bee * b = board[board_index].bees.front();
        remove_bee(board_index, board[board_index].bees.begin());
        delete[] b;
    }
}

/**
 * Moves the bee forward one space
 * 
 * @param int board_index current position of the bee on the board
 * @param vector<Bee*>::iterator pointer to bee in vector
 * 
 * @returns bool true if bee moves to index -1 (Game is lost)
 */
bool Board::move_bee(int board_index, vector<Bee*>::iterator it)
{
    if (board_index == 0) return true;

    Bee * b = *it;

    remove_bee(board_index, it);

    if (board[board_index].isNinja && !b->damage())
        add_bee(board_index-1, b);

    return false;
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

    b->set_bee_position(board_index-1);
}

/**
 * Deletes the bee at the given index of a square
 * 
 * @param int board_index index of the square
 * @param vector<Bee*> iterator pointer to bee in vector
 */
void Board::remove_bee(int board_index, vector<Bee*>::iterator it)
{
    vector<Bee*> bees = board[board_index].bees;
    bees.erase(it);

    board[board_index].num_bees--;
    total_num_bees--;
}