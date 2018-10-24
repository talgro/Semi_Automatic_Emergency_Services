//
// Created by tal on 27/08/18.
//

#include <iostream>
#include "Force_Army_I.hpp"
#include "Event.hpp"

Force_I::Exception_NoAvailableUnits Force_Army_I::_NoAvailableArmyUnits("army");

void Force_Army_I::controlSituation() {
    getToAddress();
    if (_currEvent->civiliansAround()){
        moveCiviliansAway();
    }
    if (_currEvent->numTerroristsInvolved() > 0){
        takeCareOfCamouflage();
        killTerroristsBySpecialty();
    }
    if (_currEvent->manDown()){
        evacuateBody();
    }
}

void Force_Army_I::moveCiviliansAway() {
    cout << "Military Unit: All citizens, move away from here" << endl;
}

void Force_Army_I::evacuateBody() {
    cout << "Military Unit: evacuating body" << endl;
}