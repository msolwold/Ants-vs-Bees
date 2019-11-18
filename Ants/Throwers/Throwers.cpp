/**
 * Thrower type ant
 * 
 * These ants have an active attack
 * 
 */

#include "Throwers.h"

// * Constructors

Throwers::Throwers()
{
    attacked = false;

    Ant::blocking = true;
    Ant::attacker = true;
    Ant::proactive = true;
}

Throwers::Throwers(const Throwers &a)
{
    std::cout << "copying thrower" << std::endl;
    Ant::ant_type = a.ant_type;
    Ant::armor = a.armor;
    Ant::health = 1;
    Ant::cost = a.cost;
    Ant::blocking = a.blocking;
    Ant::proactive = a.proactive;
    Ant::attacker = a.attacker;
    Throwers::min_range = a.min_range;
    Throwers::max_range = a.max_range;
    Throwers::attacked = a.attacked;
}

// * Accessors

/**
 * Returns the min attack range of the Ant
 * 
 * @return int
 */
int Throwers::get_min_range() const
{
    return min_range;
}

/**
 * Returns the max attack range of the Ant
 * 
 * @return int
 */
int Throwers::get_max_range() const
{
    return max_range;
}

/**
 * Returns true if the Ant has attacked this round
 * 
 * @return bool
 */
bool Throwers::hasAttacked() const 
{
    return attacked;
}

// * Mutators

/**
 * Finds the closest bee inside of the ants attack range and deals 1 damage to it
 * If the ant kills the bee, kill_bee() is called and the bee is removed
 * 
 * @param Board * b pointer to board object
 */
void Throwers::attack(Board * b)
{
    attacked = true;
    
    int start = position + min_range;
    int end = position + max_range+1;

    Board::Square * board = b->get_board();

    for (int i = start; i < end; i++)
    {
        if (i > b->get_board_size()-1) break;

        if (board[i].num_bees > 0)
        {
            if (board[i].bees.front()->damage())
                b->kill_bee(i, board[i].bees.front());

            break;
        }
    }
}

/**
 * Refreshes the Ant. Sets the Attacked flag to false
 */
void Throwers::refresh_ant()
{
    attacked = false;
}