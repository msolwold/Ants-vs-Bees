/**
 * Ant Base Class
 * 
 * Abstract Class
 * Parent: None
 * Children: Throwers, Harvester, Fire, Wall, Ninja, Bodyguard
 */

#ifndef ANT_H
#define ANT_H

#include <string>
#include <iostream>

class Ant {

    public:

        // * Constructor

        Ant();
        Ant(const Ant &a);

        virtual Ant * clone() const = 0;

        // * Destructor

        ~Ant();
        
        // * Accessors

        virtual std::string get_ant_action() const = 0;
        std::string get_ant_type() const;
        int get_ant_health() const;
        int get_ant_armor() const;
        int get_ant_cost() const;

        bool isAlive() const;
        bool isBlocking() const;
        bool isProactive() const;
        bool isAttacker() const;

        // ! For Thrower Types, implement with an exception
        virtual int get_min_range() const;
        virtual int get_max_range() const;
        virtual bool hasAttacked() const;
        virtual void attack();
        virtual void refresh_ant();

        // * Mutators
        
        bool damage();

    protected:

        //Unique
        std::string ant_type;
        int health;
        int armor;
        int cost;
        bool blocking; // Blocks the bees from moving (Ninja is only ant)
        bool proactive;
        bool attacker;

    private:

        bool alive;

};

#endif