//
// Created by tal on 27/08/18.
//

#include <iostream>
#include "Force_Medical_I.hpp"
#include "Event.hpp"

const Force_I::Exception_NoAvailableUnits Force_Medical_I::_NoAvailableMedicalUnits("medical");

void Force_Medical_I::controlSituation() {
    getToAddress();
    sortPatientsByUrgency();
    if (_currEvent->numInjured() > 1){
        sortPatientsByUrgency();
    }
    giveFirstAid();
    performSpecialty();
    evacuateToHospital();
}

void Force_Medical_I::sortPatientsByUrgency() {
    cout << "Medical: Sorting patients by urgency" << endl;
}

void Force_Medical_I::giveFirstAid() {
    cout << "Medical: giving first aid" << endl;
}