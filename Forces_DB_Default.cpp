//
// Created by tal on 27/08/18.
//

#include <algorithm>
#include "Forces_DB_Default.hpp"
#include "Force_I.hpp"
#include "Force_Police_I.hpp"
#include "Force_Army_I.hpp"
#include "Force_FireFighting_I.hpp"
#include "Force_Medical_I.hpp"
#include "Forces_Visitor.hpp"

//Default_Adder
Forces_DB_Default::Default_Adder::Default_Adder(Forces_DB_Default *father)
    : _father(father){}

void Forces_DB_Default::Default_Adder::visit(Force_Army_I *unit) {
    _father->_armyForces.push_back(unit);
}

void Forces_DB_Default::Default_Adder::visit(Force_Medical_I *unit) {
    _father->_medicalForces.push_back(unit);
}

void Forces_DB_Default::Default_Adder::visit(Force_FireFighting_I *unit) {
    _father->_fireForces.push_back(unit);
}

void Forces_DB_Default::Default_Adder::visit(Force_I *unit) {
    int g;
}

void Forces_DB_Default::Default_Adder::visit(Force_Police_I *unit) {
    _father->_policeForces.push_back(unit);
}

//Default_Eraser
Forces_DB_Default::Default_Eraser::Default_Eraser(Forces_DB_Default *father)
        : _father(father){}

void Forces_DB_Default::Default_Eraser::visit(Force_Army_I *unit) {
    auto it = find(_father->_armyForces.begin(), _father->_armyForces.end(), unit);
    _father->_armyForces.erase(it);
}

void Forces_DB_Default::registerNewUnit(Force_I *unitType) {
    Force_I* unitTypeCopy = unitType->clone();
    _unitTypes.push_back(unitTypeCopy);
}

void Forces_DB_Default::Default_Eraser::visit(Force_Medical_I *unit) {
    auto it = find(_father->_medicalForces.begin(), _father->_medicalForces.end(), unit);
    _father->_medicalForces.erase(it);
}

void Forces_DB_Default::Default_Eraser::visit(Force_FireFighting_I *unit) {
    auto it = find(_father->_fireForces.begin(), _father->_fireForces.end(), unit);
    _father->_fireForces.erase(it);
}

void Forces_DB_Default::Default_Eraser::visit(Force_Police_I *unit) {
    auto it = find(_father->_policeForces.begin(), _father->_policeForces.end(), unit);
    _father->_policeForces.erase(it);
}

void Forces_DB_Default::Default_Eraser::visit(Force_I *unit) {
    int t;
}

//Forces_DB_Default
Forces_DB_Default::Forces_DB_Default(KeyToCtor){
    _adderComponent = new Default_Adder(this);
    _eraserComponent = new Default_Eraser(this);
}

const vector<Force_I*>* const Forces_DB_Default::availablePolice() {
    return &_policeForces;
}

const vector<Force_I*>* const Forces_DB_Default::availableMedical() {
    return &_medicalForces;
}

const vector<Force_I*>* const Forces_DB_Default::availableFireFighting() {
    return &_fireForces;
}

const vector<Force_I*>* const Forces_DB_Default::availableArmy() {
    return &_armyForces;
}

const vector<Force_I*>* const Forces_DB_Default::existingUnitTypes() {
    return &_unitTypes;
}
