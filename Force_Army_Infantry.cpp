//
// Created by tal on 01/09/18.
//

#include <iostream>
#include "Force_Army_Infantry.hpp"

void Force_Army_Infantry::getToAddress() {
    cout << "Infantry Unit: on our way to destination by foot" << endl;
}

void Force_Army_Infantry::takeCareOfCamouflage() {
    cout << "Infantry Unit: putting camouflage on face" << endl;
}

void Force_Army_Infantry::killTerroristsBySpecialty() {
    cout << "Infantry Unit: killing terrorists with M-16" << endl;
}

string Force_Army_Infantry::getTypeName() {
    return "Infantry";
}

Force_I *Force_Army_Infantry::clone() {
    return new Force_Army_Infantry(*this);
}

void Force_Army_Infantry::accept(Forces_Visitor *visitor) {
    visitor->visit(this);
}
