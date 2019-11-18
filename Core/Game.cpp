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
    cout << "Initializing Game...\n\n";

    board = new Board();
    player = new Player();
    create_ant_templates();
}

/**
 * Engine of the game
 * 
 * Runs while there are Bees on the Board and the Queen is still alive
 * 
 * Returns 1 if the game ends with the Queen Alive
 * Returns 0 if the game ends with the Queens Death
 * 
 * @return bool
 */
int Game::run()
{

    cout << "------ Starting Game ------" << endl
         << endl;
    //core - Do while to force game to run once
    do
    {
        player->print_player_info(board->get_total_num_harvesters());

        spawn_bee();

        print_board();

        player_turn();

        print_board();

        if (ants_attack()) return 1; 
        if (bees_attack()) return 0;


        refresh_board();

    } while (isActive());
    // if player is alive return 1, is player dies return 0
    if (board->queen_isAlive())
        return 1;
    else
        return 1;
}

// * Helpers

/**
 * Returns false if queen is dead or if there are no bees on the board
 * 
 * @return bool
 */
bool Game::isActive()
{
    return board->queen_isAlive() && board->get_total_num_bees() > 0;
}

/**
 * Function that creates templates for each ant type
 * Used for easy printing and ant creation
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

/**
 * Calls the refresh board function in the board class
 * 
 * Adds the number of resources gained from Harvesters to the players Resource Total
 */
void Game::refresh_board()
{
    player->add_resources(board->refresh_board());
}

/**
 * Function that calls all of the actions the player has on their turn
 * 
 * Select Ant
 * Select Position
 * Place Ant
 */
void Game::player_turn()
{

    int player_ant_selection;
    int player_location_selection;

    while (true)
    {

        player_ant_selection = get_player_ant_choice() - 1;
        player_location_selection = get_player_location_choice(player_ant_selection) - 1;

        if (player_location_selection != -2)
            break;
    }

    cout << "You've chosen to place a " << ant_list[player_ant_selection]->get_ant_type()
         << " ant at position " << (player_location_selection + 1) << endl;

    board->place_ant(player_location_selection, create_ant(player_ant_selection));
}

/**
 * Returns the index of the Ant the player has chosen
 * 
 * @return bool
 */
int Game::get_player_ant_choice()
{

    print_ant_list();
    int selection;

    while (true)
    {
        cin.clear();
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

/**
 * Returns the location the player would like to place the Ant
 * 
 * Checks if the location is valid given the Ant choice
 * 
 * @param int index of the Ant player has chosen
 * 
 * @return int
 */
int Game::get_player_location_choice(int ant)
{

    int selection;
    int error_choice;

    while (true)
    {
        cout << "Enter the value of the square that you would like to place your ant in: ";
        cin >> selection;

        if (selection < 1 || selection > board->get_board_size())
            cout << "The value entered was out of bounds!" << endl
                 << endl;

        else if (board->can_place_ant(selection-1, ant_list[ant]))
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

/**
 * Calls the function ant_attack() in board
 * Iterates through all the ants and calls their attack function
 * 
 * Returns true if all Bees have been killed
 * 
 * @return bool
 */
bool Game::ants_attack()
{
    return board->ants_attack();
}

/**
 * Create a new Ant using the ant_list array
 * 
 * @param int ant_index index of the ant the user would like to place
 * 
 * @return Ant *
 */
Ant *Game::create_ant(int ant_index)
{
    player->sub_resources(ant_list[ant_index]->get_ant_cost());
    return ant_list[ant_index]->clone();
}

/**
 * Calls the function bees_attack() in board
 * Iterates through all of the bees and tries to move/attack
 * 
 * Returns true if a bee moves to the Queen (Index -1)
 * 
 * @return bool
 */
bool Game::bees_attack()
{
    return board->bees_action();
}

/**
 * Calls the function spawn_bee() in the Board Class
 * 
 * Spawns a Bee on the board
 */
void Game::spawn_bee()
{
    board->spawn_bee();
}

// * Print Statements

/**
 * Output the current status of the board
 */
void Game::print_board()
{
    board->print_board();
}

/**
 * Outputs a list of all Ants with their Cost, Armor, and Actions.
 */
void Game::print_ant_list()
{

    cout << "Please select an ant to place:\n"
         << endl;

    for (int i = 0; i < num_ant_types; i++)
    {
        cout << "(" << i+1 << "). " << ant_list[i]->get_ant_type() << ":" << endl;
        cout << "   Cost: " << ant_list[i]->get_ant_cost() << " fruit(s)" << endl;
        cout << "   Armor: " << ant_list[i]->get_ant_armor() << endl;
        cout << "   Stops Bees from Passing : " << (ant_list[i]->isBlocking() ? "Yes\n" : "No\n");
        cout << "   Action: " << ant_list[i]->get_ant_action() << endl;
    }
    cout << endl;
}

Game::~Game()
{
    delete board;
    delete player;
}