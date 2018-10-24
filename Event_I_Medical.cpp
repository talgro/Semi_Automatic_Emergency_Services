//
// Created by tal on 02/09/18.
//

#include "Event_I_Medical.hpp"

Event_I_Medical::Event_I_Medical(bool evacuationRequired, bool deadBodies, int numInjured)
    : _evacuationRequired(evacuationRequired), _deadBodies(deadBodies), _numInjured(numInjured){}

Event_I_Medical::~Event_I_Medical(){}   //to make abstract

bool Event_I_Medical::isMedicalRequired(){
    if (_deadBodies || _numInjured > 0 || _evacuationRequired){
        return true;
    }
    return false;
};