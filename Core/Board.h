/**
 * Board class
 * Holds an array of Square structs and info about the current state
 * of the board
 * 
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>

#include "../Ants/Ant.h"
#include "Bee.h"

class Board {

public:

    // * Struct to place in each square of the board
    struct Square
    {
        std::vector<Ant *> ants;
        std::vector<Bee *> bees;

        Ant * Bodyguard;

        bool isBodyguard;
        bool isAnt;
        bool isNinja;
        bool isBlocked;

        int num_ants;
        int num_bees;
    };

    // * Constructors

    Board();

    // ? Dont wanna do a copy constructor since ill
    // ? be passing the pointer

    // * Destructor

    ~Board();

    // * Accessors

    int get_board_size() const;
    Square * get_board() const;

    int get_total_num_ants() const;
    int get_total_num_bees() const;
    int get_total_num_harvesters() const;

    bool isBodyguard(int index) const;
    bool isAnt(int index) const;
    bool isNinja(int index) const;
    bool isBlocked(int index) const;
    int get_num_ants(int index) const;
    int get_num_bees(int index) const;

    bool queen_isAlive() const;

    bool can_place_ant(int index, const Ant *a) const;    // Try to place the ant/bee, return false if unable

    // * Turn Functions

    //*Ants
    bool ants_attack();
    
    //*Bees
    void spawn_bee();
    bool bees_action();         // For each bee, attempt to move forward + Attack
    void bee_attack(int board_index, Bee * b);


    // * Mutators

    void refresh_square(int index);
    int refresh_board();

    void place_ant(int index, Ant * a);         // Used during players turn
    void kill_bee(int board_index, Bee * b);    // Used by Throwers

    // * Helpers

    void print_board() const;
    std::string print_border() const;
    std::string print_ants(std::vector<Ant*>::iterator it, std::vector<Ant*>::iterator beginning) const;
    std::string print_bees(std::vector<Bee*>::iterator it, std::vector<Bee*>::iterator end) const;
    std::string print_inner_square(int index, int i) const;
    

private:

    int board_size;         // If I ever wanted to extend the board
    Square * board;

    int total_num_ants;
    int total_num_bees;
    int total_num_harvesters;

    bool queen_alive;

    // * Helpers

    void create_board();

    // * Turn Functions

    //*Ants
    void remove_ant(int board_index, std::vector<Ant*>::iterator it);


    //*Bees
    bool can_move_bee(int index, const Bee * b) const;    
    bool move_bee(int board_index, std::vector<Bee*>::iterator it);
    void kill_all_bees(int board_index);

    void remove_bee(int board_index, std::vector<Bee*>::iterator it);
    void add_bee(int board_index, Bee * b);
};

#endif