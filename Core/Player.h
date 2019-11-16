/**
 * Player Class
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player
{

public:
    // * Constructors

    Player();
    Player(const std::string player_name);
    Player(const Player &p);

    // * Destructor

    ~Player();

    // * Accessors

    int get_num_resources();
    bool isAlive();
    std::string get_player_name();

    // * Mutators
    void set_player_name(std::string player_name);

    void add_resources(int r);
    void sub_resources(int r);

private:
    int resources;

    bool queen_alive;

    std::string player_name;

    // * Helpers
};

#endif