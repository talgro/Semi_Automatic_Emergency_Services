//
// Created by tal on 27/08/18.
//

#include <iostream>
#include "Force_FireFighting_I.hpp"
#include "Event.hpp"

Force_I::Exception_NoAvailableUnits Force_FireFighting_I::_NoAvailableFireFightingUnits("Fire Fighting");

void Force_FireFighting_I::controlSituation() {
    getToAddress();
    if (_currEvent->hasFire()){
        recognizeFireSource();
        if(_currEvent->numOfTrapped() > 0){
            rescueTrapped();
        }
        performSpecialty();
    }
    if (_currEvent->numOfCatsOnTree() > 0){
        rescueCats();
    }
}

void Force_FireFighting_I::recognizeFireSource() {
    cout << "Fire Fighters: looking for fire source..." << endl;
}

void Force_FireFighting_I::rescueCats() {
    cout << "Fire Fighters: rescuing cats from tree" << endl;
}

void Force_FireFighting_I::rescueTrapped() {
    cout << "Fire Fighters: rescuing trapped people" << endl;
}