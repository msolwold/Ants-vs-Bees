/**
 * Player Class
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

    ~Player(){}

    // * Accessors

    int get_num_resources() const;
    std::string get_player_name() const;

    // * Mutators
    void set_player_name(std::string player_name);

    void add_resources(int r);
    void sub_resources(int r);

    void print_player_info(int num_harvesters) const;

private:
    int resources;

    std::string player_name;
};

#endif