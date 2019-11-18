/**
 * Game
 * 
 */

#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <vector>

#include "../Ants/Ant.h"
#include "Bee.h"
#include "Player.h"
#include "Board.h"

// ! This is gross
#include "../Ants/Ant_Harvester.h"
#include "../Ants/Ant_Fire.h"
#include "../Ants/Ant_Ninja.h"
#include "../Ants/Ant_Wall.h"
#include "../Ants/Ant_Bodyguard.h"
#include "../Ants/Throwers/Ant_Thrower.h"
#include "../Ants/Throwers/Ant_ShortThrower.h"
#include "../Ants/Throwers/Ant_LongThrower.h"

class Game
{

public:
    // * Constructors

    Game();

    // ? Dont need to create copy constructors

    // * Destructor

    ~Game();

    // * Accessors

    int run();

    // * Mutators

private:

    Player *player;
    Board *board;

    Ant **ant_list;    // templates of each ant type
    int num_ant_types; // If new ants are added

    // * Helpers

    void create_board();
    bool isActive(); // return queen status and num_bees > 0

    void create_ant_templates(); // fills ant_list array

    // TODO
    void check_square(int index); // Print Space Information (toString for the struct)
    
    void refresh_board();       // Run every turn to check the status of each square and reset bee attack flag

    // * Turn Helpers

    //*Player
    void player_turn();
    int get_player_ant_choice();
    int get_player_location_choice(int ant);

    //*Ants
    bool ants_attack();
    Ant *create_ant(int ant_index);

    //*Bees
    bool bees_attack();
    void spawn_bee();

    // * Print Statements

    void print_board();
    void print_ant_list();
};

#endif