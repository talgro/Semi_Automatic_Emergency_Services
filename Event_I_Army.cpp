//
// Created by tal on 02/09/18.
//

#include "Event_I_Army.hpp"

Event_I_Army::Event_I_Army(bool civiliansAround, bool manDown, int numTerroristsInvolved)
    : _civiliansAround(civiliansAround), _manDown(manDown), _numTerroristsInvolved(numTerroristsInvolved){}

Event_I_Army::~Event_I_Army(){}   //to make abstract

bool Event_I_Army::isArmyRequired(){
    if (_manDown || _numTerroristsInvolved > 0 || _civiliansAround){
        return true;
    }
    return false;
};