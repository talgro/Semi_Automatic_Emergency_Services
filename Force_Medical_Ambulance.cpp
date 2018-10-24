//
// Created by tal on 01/09/18.
//

#include <iostream>
#include "Force_Medical_Ambulance.hpp"

void Force_Medical_Ambulance::getToAddress() {
    cout << "Ambulance is on the way to the event location" << endl;
}

Force_I *Force_Medical_Ambulance::clone() {
    return new Force_Medical_Ambulance(*this);
}

void Force_Medical_Ambulance::accept(Forces_Visitor *visitor) {
    visitor->visit(this);
}

void Force_Medical_Ambulance::performSpecialty() {
    cout << "Ambulance specialty: Drive fast and with siren" << endl;
}

void Force_Medical_Ambulance::evacuateToHospital() {
    cout << "Ambulance: evacuating to hospital" << endl;
}

string Force_Medical_Ambulance::getTypeName() {
    return "Ambulance";
}