//
// Created by tal on 27/08/18.
//

#include "Force_Police_I.hpp"
#include "Event_I_Police.hpp"
#include "Event.hpp"
#include <iostream>

Force_I::Exception_NoAvailableUnits Force_Police_I::_NoAvailablePoliceUnits("police");

void Force_Police_I::controlSituation() {
    getToAddress();
    if (_currEvent->estimatedNumCriminals() > 0){
        if (_currEvent->shotsFired()){
            getCrowdAway();
            weaponsOut();
            loadBullet();
        }
        beCareful();
        warnCriminals();
        performSpecialty();
        killCriminals();
    }
    else{
        falseAlarm();
    }
}

void Force_Police_I::getCrowdAway() {
    cout << "Police officer is yelling: 'Please move away from here!@#$ everybody move!!!!!" << endl;
}

void Force_Police_I::weaponsOut() {
    cout << "Police officer has just pulled his weapon out!" << endl;
}

void Force_Police_I::loadBullet() {
    cout << "Police officer has just loaded bullets!" << endl;
}

void Force_Police_I::warnCriminals() {
    cout << "Police officer is yelling: 'Dear criminals, please get out, we don't want to shoot you!!!" << endl;
}

void Force_Police_I::beCareful() {
    cout << "Police officer is acting very carefully..." << endl;
}

void Force_Police_I::killCriminals() {
    cout << "PEW PEW PEW! Police officer has just killed a criminal" << endl;
}

void Force_Police_I::falseAlarm() {
    cout << "Police officer: 'Nothing here?! back to my donuts...'" << endl;
}
