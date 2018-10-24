//
// Created by tal on 29/08/18.
//

#include "Force_Police_Car.hpp"
#include "Event_I_Police.hpp"
#include <iostream>
#include "Event.hpp"

void Force_Police_Car::performSpecialty() {
    cout << "Police car specialty: throw 4 donuts on the criminals" << endl;
}

Force_I *Force_Police_Car::clone() {
    return new Force_Police_Car(*this);
}

void Force_Police_Car::getToAddress() {
    cout << "Police car is on the way to the event location" << endl;
}

void Force_Police_Car::accept(Forces_Visitor *visitor) {
    visitor->visit(this);
}

string Force_Police_Car::getTypeName() {
    return "Police-Car";
}
