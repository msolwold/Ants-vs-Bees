/**
 * Game Class
 * 
 * Top Level:
 *      Array of size 10 (board)
 *      Each index holds square struct (square)
 *      Queen ant in index 0 
 *      "beehive" on index 10, bees spawn on index 9
 *      tracks how many bees are present on the board
 * 
 * Low Level:
 *      space struct:
 *          holds a vector
 *          tracks how many bees and ants are present
 *          tracks if the square is blocked
 *          tracks if a body guard is present
 * 
 *  TODO: Destructor
 * 
 */

#include <string>
#include <iostream>

#include "Game.h"

using namespace std;

Game::Game()
{

    board = new Square[10];
    player = new Player();

    num_bees = 0;
    num_ants = 0;
}

int Game::run()
{

    cout << "------ Starting Game ------" << endl
         << endl;
    create_board();

    //core - Do while to force game to run once
    // ? Move to own func?
    do
    {

        spawn_bee();

        player_turn();

        ant_attack(); // TODO
        bee_attack();

    } while (isActive());

    // if player is alive return 1, is player dies return 0
    if (player->isAlive())
        return 1;
    else
        return 0;
}

// * Helpers

void Game::create_board()
{

    for (int i = 0; i < 10; i++)
    {

        board[i].isBodyguard = false;
        board[i].isAnt = false;
        board[i].isNinja = false;
        board[i].isBlocked = false;

        board[i].num_ants = 0;
        board[i].num_bees = 0;
    }
}

/**
 * 
 * Returns false if queen is dead or if there are no bees on the board
 * 
 */
bool Game::isActive()
{
    return player->isAlive() && num_bees > 0;
}

/**
 * 
 * Function that creates templates for each ant type
 * Used for easy printing and ant creation
 * 
 */
void Game::create_ant_templates()
{

    // Modular for new ants added to the game
    num_ant_types = 8;
    ant_list = new Ant *[num_ant_types];

    ant_list[0] = new Ant_Harvester();
    ant_list[1] = new Ant_Fire();
    ant_list[2] = new Ant_Ninja();
    ant_list[3] = new Ant_Thrower();
    ant_list[4] = new Ant_ShortThrower();
    ant_list[5] = new Ant_LongThrower();
    ant_list[6] = new Ant_Wall();
    ant_list[7] = new Ant_Bodyguard();
}

void Game::player_turn()
{

    int player_ant_selection;
    int player_location_selection;

    while (true)
    {

        player_ant_selection = get_player_ant_choice() - 1;
        player_location_selection = get_player_location_choice(player_ant_selection) - 1;

        if (player_location_selection != -1)
            break;
    }

    cout << "You've chosen to place a " << ant_list[player_ant_selection]->get_ant_type()
         << " ant at position " << player_location_selection + 1;

    place_ant(player_location_selection, create_ant(player_ant_selection));
}

int Game::get_player_ant_choice()
{

    print_ant_list();
    int selection;

    while (true)
    {

        cout << "Enter the value of the ant you would like to place: ";
        cin >> selection;

        if (selection < 1 || selection > num_ant_types)
            cout << "Your choice was out of the range of valid choices!" << endl
                 << endl;

        else if (ant_list[selection - 1]->get_ant_cost() > player->get_num_resources())
            cout << "That ant is too expensive!" << endl
                 << endl;

        else
            break;
    }

    cout << "You selected the " << ant_list[selection - 1]->get_ant_type() << " ant" << endl
         << endl;

    return selection;
}

int Game::get_player_location_choice(int ant)
{

    int selection;
    int error_choice;

    while (true)
    {

        cout << "Enter the value of the square that you would like to place your ant in: ";
        cin >> selection;

        if (selection < 1 || selection > 10)
            cout << "The value entered was out of bounds!" << endl
                 << endl;

        else if (can_place_ant(selection, ant_list[ant]))
            break;

        while (true)
        {

            cout << endl;
            cout << "Would you like to try a different position or choose a new Ant?" << endl;
            cout << "Enter 0 to try again or 1 to choose a new Ant: ";

            cin >> error_choice;

            if (error_choice == 0)
                break;
            if (error_choice == 1)
                return -1;

            cout << "Invalid Entry!" << endl
                 << endl;
        }
    }

    return selection;
}

Ant *Game::create_ant(int ant_index)
{
    return ant_list[ant_index]->clone;
}

/**
 * 
 * Returns true if the ant can be placed at the given location
 * 
 * @param int selection index on the board
 * @param Ant * ant being placed
 */
bool Game::can_place_ant(int selection, Ant *a)
{

    if (a->get_ant_type() == "Bodyguard" && board[selection].isBodyguard)
    {

        cout << "You cannot place another Bodyguard in this position!" << endl;
        return false;
    }

    else if (board[selection].isAnt)
    {

        cout << "There is already an ant at this position!" << endl;
        return false;
    }

    return true;
}

void Game::place_ant(int index, Ant *a)
{

    board[index].ants.push_back(a);

    if (a->get_ant_type() == "Bodyguard")
    {
        board[index].isBodyguard = true;
        board[index].isBlocked = true;
    }

    else if (a->get_ant_type() == "Ninja")
    {
        board[index].isNinja = true;
        board[index].isAnt = true;
    }

    else
    {
        board[index].isAnt = true;
        board[index].isBlocked = true;
    }

    num_ants++;
    board[index].num_ants++;
}

// * Print Statements

void Game::print_board()
{
}

void Game::print_ant_list()
{

    cout << "Please select an ant to place:\n"
         << endl;

    for (int i = 0; i < num_ant_types; i++)
    {
        cout << "(" << i << "). " << ant_list[i]->get_ant_type() << ":" << endl;
        cout << "   Cost: " << ant_list[i]->get_ant_cost() << endl;
        cout << "   Armor: " << ant_list[i]->get_ant_armor() << endl;
        cout << "   Action: " << ant_list[i]->get_ant_action() << endl;
    }
}