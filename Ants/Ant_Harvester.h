/**
 * Harvester Ant
 * 
 * Parent: Ant
 */

#ifndef ANT_HARVESTER_H
#define ANT_HARVESTER_H

#include "Ant.h"

class Ant_Harvester : public Ant
{

public:
    // * Constructor

    Ant_Harvester();

    virtual Ant_Harvester *clone() const;

    // * Destructor

    ~Ant_Harvester();

    virtual std::string get_ant_action() const;
    virtual std::string ant_type() const;

private:
    std::string type;
};

#endif