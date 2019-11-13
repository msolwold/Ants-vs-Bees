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

Game::Game(){

    board = new Square[10];
    player = new Player();

    num_bees = 0;
    num_ants = 0;
}

int Game::run(){

    cout << "------ Starting Game ------" << endl << endl;
    create_board();

    //core - Do while to force game to run once
    // ? Move to own func?
    do {

        spawn_bee();
        
        player_turn();

        ant_attack();
        bee_attack();


    } while (isActive());

    // if player is alive return 1, is player dies return 0
    if (player->isAlive()) return 1;
    else return 0;

}


// * Helpers

void Game::create_board(){

    for (int i = 0; i < 10; i++){
        
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
bool Game::isActive(){

    return player->isAlive() && num_bees > 0;
}

/**
 * 
 * Function that creates templates for each ant type
 * Used for easy printing and ant creation
 * 
 */ 
void Game::create_ant_templates(){
    
    // Modular for new ants added to the game
    num_ant_types = 8;
    ant_list = new Ant*[num_ant_types];

    ant_list[0] = new Ant_Harvester();
    ant_list[1] = new Ant_Fire();
    ant_list[2] = new Ant_Ninja();
    ant_list[3] = new Ant_Thrower();
    ant_list[4] = new Ant_ShortThrower();
    ant_list[5] = new Ant_LongThrower();
    ant_list[6] = new Ant_Wall();
    ant_list[7] = new Ant_Bodyguard();
}

void Game::player_turn(){

    print_ant_list();
}

// * Print Statements

void print_board(){

}

void print_ant_list(){

    cout << "Please select an ant to place:\n" << endl; 

    for (int i = 0; i < num_ant_types; i++){
        cout << "(" << i << "). " << ant_list->
    }
}