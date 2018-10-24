//
// Created by tal on 02/09/18.
//

#include "Event_I_Police.hpp"

Event_I_Police::Event_I_Police(bool shotsFired, bool isDangerous, int estimatedNumCriminals)
    : _shotsFired(shotsFired), _isDangerous(isDangerous), _estimatedNumCriminals(estimatedNumCriminals){}

Event_I_Police::~Event_I_Police(){}   //to make abstract

bool Event_I_Police::isPoliceRequired(){
    if (_shotsFired || _isDangerous > 0 || _estimatedNumCriminals > 0){
        return true;
    }
    return false;
};