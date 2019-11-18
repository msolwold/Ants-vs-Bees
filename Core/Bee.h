/**
 * Bee Class
 */

#ifndef BEE_H
#define BEE_H

class Bee
{

public:
    // * Constructors

    Bee();

    // * Destructor

    //~Bee();

    // * Accessors

    int get_bee_health() const;
    int get_bee_armor() const;
    bool isAlive() const;

    int get_bee_position() const;
    bool hasAttacked() const;

    // * Mutators

    void set_bee_position(int index);
    void attack();
    void refresh_bee();                 // Reset the attacked flag

    bool damage(int damage = 1);        // taking an int for fire ant, 1 is default

private:
    int health;
    int armor;
    bool alive;

    int position;
    bool attacked;
};

#endif