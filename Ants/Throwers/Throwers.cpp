/**
 * Thrower type ant
 * 
 * These ants have an active attack
 * 
 */

#include "Throwers.h"
#include "../Core/Board.h"

Throwers::Throwers()
{
    attacked = false;

    Ant::blocking = true;
    Ant::attacker = true;
    Ant::proactive = true;
}

Throwers::Throwers(const Throwers &a)
{
    Throwers::min_range = a.min_range;
    Throwers::max_range = a.max_range;
    Throwers::attacked = a.attacked;
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