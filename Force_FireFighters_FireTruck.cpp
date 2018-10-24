//
// Created by tal on 01/09/18.
//

#include <iostream>
#include "Force_FireFighters_FireTruck.hpp"

void Force_FireFighters_FireTruck::getToAddress() {
    cout << "Fire truck is on the way to event location" << endl;
}

void Force_FireFighters_FireTruck::performSpecialty() {
    cout << "Ambulance specialty: Spray water and turn on siren" << endl;
}

string Force_FireFighters_FireTruck::getTypeName() {
    return "Fire-Truck";
}

void Force_FireFighters_FireTruck::accept(Forces_Visitor *visitor) {
    visitor->visit(this);
}

Force_I *Force_FireFighters_FireTruck::clone() {
    return new Force_FireFighters_FireTruck(*this);
}
