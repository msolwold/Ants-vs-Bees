/**
 * Game
 * 
 */

#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>
#include <vector>

#include "Player.h"
#include "../Ants/Ant.h"
#include "Bee.h"


class Game {

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

        // * Struct to place in each square of the board
        struct Square {

            std::vector<Ant *> ants;
            std::vector<Bee *> bees;

            bool isBodyguard;
            bool isAnt;
            bool isNinja;
            bool isBlocked;

            int num_ants;
            int num_bees;

        };

        Player * player;
        Square * board;

        Ant ** ant_list;                    // templates of each ant type
        int num_ant_types;                  // If new ants are added

        int num_bees;
        int num_ants;

        // * Helpers

        void create_board();
        bool isActive();                    // return queen status and num_bees > 0

        void create_ant_templates();        // fills ant_list array

        void check_square(int index);       // Print Space Information (toString for the struct)
        void refresh_squares();             // Run every turn to check the status of each square and reset bee attack flag

        void spawn_bee();
        void bee_attack();
        void move_bee(int curr, int dest, Bee * b);
        void kill_bee(int index, Bee * b);

        void player_turn();
        bool place_ant(int index, Ant * a); // Try to place the ant, return false if unable
        void ant_attack();
        void get_action(Ant * a);
        void kill_ant(int index, Ant * a); 

        // * Print Statements

        void print_board();
        void print_ant_list();
        void print_place_ant();

};

#endif