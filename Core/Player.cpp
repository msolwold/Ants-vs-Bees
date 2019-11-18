/**
 * Player Class
 * 
 * Holds:
 * 
 * Resources
 * Status of Queen
 * 
 * Player info
 * 
 * TODO: Destructor
 * 
 */

#include <string>
#include <iostream>

#include "Player.h"

using namespace std;

Player::Player()
{
    cout << "Creating Player...\n\n";

    resources = 50;
}

// * Accessors

/**
 * Returns the current amount of resources that the player has
 * 
 * @return int
 */
int Player::get_num_resources() const
{
    return resources;
}

/**
 * Returns the name of the player
 * 
 * @return string
 */
string Player::get_player_name() const
{
    return player_name;
}

// * Mutators

/**
 * Sets the players name
 * 
 * @param string name
 */
void Player::set_player_name(string name)
{
    player_name = name;
}

/**
 * Adds a given amount of resources to a player
 * 
 * @param int resources
 */
void Player::add_resources(int r)
{
    cout << r << " added to your total number of resources" << endl;
    resources += r;
}

/**
 * Subtracts a given amount of resources from a player
 * 
 * @param int resources
 */
void Player::sub_resources(int r)
{
    resources -= r;
}

/**
 * Prints the number of resources the player currently has
 * 
 * @param int number of harvesters on the board
 */
void Player::print_player_info(int num_harvesters) const
{
    cout << "You currently have a total of " << resources 
        << " and are generating " << num_harvesters 
        << " additional resources per round." 
        << endl << endl;
}