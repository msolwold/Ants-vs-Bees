/**
 * BodyGuard Ant
 * 
 * Parent: Ant
 */

#ifndef ANT_BODYGUARD_H
#define ANT_BODYGUARD_H

#include "Ant.h"

class Ant_Bodyguard : public Ant
{

public:
    // * Constructor

    Ant_Bodyguard();

    virtual Ant_Bodyguard *clone() const;

    // * Destructor

    virtual ~Ant_Bodyguard(){}

    virtual std::string get_ant_action() const;
    virtual std::string get_ant_initials() const;

private:
    std::string type;
};

#endif