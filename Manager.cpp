//
// Created by tal on 27/08/18.
//
#include <algorithm>
#include "Event.hpp"
#include "Manager.hpp"
#include "Event_DB_I.hpp"
#include "Force_I.hpp"
#include "Event_Builder.hpp"
#include "Forces_DB_I.hpp"
#include "Force_Police_I.hpp"
#include "Force_Army_I.hpp"
#include "Force_FireFighting_I.hpp"
#include "Force_Medical_I.hpp"

Manager* Manager::_singleton = nullptr;

Manager* Manager::getInstance() {
    if (_singleton == nullptr){
        _singleton = new Manager();
    }
    return _singleton;
}

Type_I* Manager::requestEventBuilder() {
    return Event_Builder::getInstance();
}

void Manager::createEventAndSendToDB(Event_Builder* eventBuilder) {
    Event* event = eventBuilder->build();
    Event_DB_I::getInstance({})->addNewEvent(event);
}

void Manager::assignUnitForEvent(Event *event){
    Manager::getInstance()->markEventAsInProgressInDB(event);
    _assignerComponent.assignUnitForEvent(event);
}

void Manager::markEventAsInProgressInDB(Event *event) {
    Event_DB_I::getInstance({})->markEventAsInProgressInDB(event);
}

void Manager::incReleventUnitsForEvent(Event *event) {
    Event_DB_I::getInstance({})->incReleventUnitsForEvent(event);
}

const vector<Force_I*>* const Manager::existingUnitTypes() {
    return Forces_DB_I::getInstance({})->existingUnitTypes();
}

const vector<Event*>* const Manager::getOpenCalls() const{
    return Event_DB_I::getInstance({})->getOpenCalls();
}

const vector<Event*>* const Manager::getArchivedCalls() const {
    return Event_DB_I::getInstance({})->getArchivedCalls();
}

const vector<Force_I*>* const Manager::getAvailableForces_Police() {
    return Forces_DB_I::getInstance({})->availablePolice();
}

const vector<Force_I*>* const Manager::getAvailableForces_Medical() {
    return Forces_DB_I::getInstance({})->availableMedical();
}

const vector<Force_I*>* const Manager::getAvailableForces_Fire() {
    return Forces_DB_I::getInstance({})->availableFireFighting();
}

const vector<Force_I*>* const Manager::getAvailableForces_Army() {
    return Forces_DB_I::getInstance({})->availableArmy();
}

void Manager::closeEvent(Event* event) {
    Event_DB_I::getInstance({})->closeEvent(event);
}

void Manager::registerUnitType(Force_I *unit) {
    Forces_DB_I::getInstance({})->registerNewUnit(unit);
}

void Manager::addUnitToDB(Force_I *unit) {
    Forces_DB_I::getInstance({})->addUnitToDB(unit);
}

void Manager::eraseUnitFromDB(Force_I *unit) {
    Forces_DB_I::getInstance({})->eraseUnitFromDB(unit);
}

Force_I* Manager::newUnitFromType(Force_I *unit) {
    return unit->clone();
}

void Manager::Assigner::assignUnitForEvent(Event *event) {
    _currEvent = event;
    size_t numReleventUnits = 0;
    if (considerPolice(event)){
        numReleventUnits++;
    }
    if (considerMedical(event)){
        numReleventUnits++;
    }
    if (considerFireFighting(event)){
        numReleventUnits++;
    }
    if (considerArmy(event)){
        numReleventUnits++;
    }
    Manager::getInstance()->incReleventUnitsForEvent(event);
    Manager::getInstance()->closeEvent(event);
}

bool Manager::Assigner::considerPolice(Event *event) {
    if (event->isPoliceRequired()){
        bool policeUnitsAreAvailable = (Forces_DB_I::getInstance({})->availablePolice()->size() > 0);
        if (policeUnitsAreAvailable){
            Force_I* unit = Forces_DB_I::getInstance({})->availablePolice()->at(0);
            Forces_DB_I::getInstance({})->eraseUnitFromDB(unit);    //unit is not available for other missions
            unit->accept(this);   //return as police unit and control current event
            return true;    //police is relevant
        }
        else{
            throw Force_Police_I::_NoAvailablePoliceUnits;
        }
    }
}

bool Manager::Assigner::considerArmy(Event *event) {
    if (event->isArmyRequired()){
        bool ArmyUnitsAreAvailable = (Forces_DB_I::getInstance({})->availableArmy()->size() > 0);
        if (ArmyUnitsAreAvailable){
            Force_I* unit = Forces_DB_I::getInstance({})->availableArmy()->at(0);
            Forces_DB_I::getInstance({})->eraseUnitFromDB(unit);    //unit is not available for other missions
            unit->accept(this);   //return as Army unit and control current event
            return true;    //army is relevant
        }
        else{
            throw Force_Army_I::_NoAvailableArmyUnits;
        }
    }
}

bool Manager::Assigner::considerFireFighting(Event *event) {
    if (event->isFireFightinglRequired()){
        bool FireFightingUnitsAreAvailable = (Forces_DB_I::getInstance({})->availableFireFighting()->size() > 0);
        if (FireFightingUnitsAreAvailable){
            Force_I* unit = Forces_DB_I::getInstance({})->availableFireFighting()->at(0);
            Forces_DB_I::getInstance({})->eraseUnitFromDB(unit);    //unit is not available for other missions
            unit->accept(this);   //return as FireFighting unit and control current event
            return true;    //fire-fighting is relevant
        }
        else{
            throw Force_FireFighting_I::_NoAvailableFireFightingUnits;
        }
    }
}

bool Manager::Assigner::considerMedical(Event *event) {
    if (event->isMedicalRequired()){
        bool MedicalUnitsAreAvailable = (Forces_DB_I::getInstance({})->availableMedical()->size() > 0);
        if (MedicalUnitsAreAvailable){
            Force_I* unit = Forces_DB_I::getInstance({})->availableMedical()->at(0);
            Forces_DB_I::getInstance({})->eraseUnitFromDB(unit);    //unit is not available for other missions
            unit->accept(this);   //return as Medical unit and control current event
            return true;    //medical is relevant
        }
        else{
            throw Force_Medical_I::_NoAvailableMedicalUnits;
        }
    }
}

void Manager::Assigner::visit(Force_Police_I *unit) {
    unit->getNewMission(_currEvent);
}

void Manager::Assigner::visit(Force_Medical_I *unit) {
    unit->getNewMission(_currEvent);
}

void Manager::Assigner::visit(Force_FireFighting_I *unit) {
    unit->getNewMission(_currEvent);
}

void Manager::Assigner::visit(Force_Army_I *unit) {
    unit->getNewMission(_currEvent);
}

void Manager::Assigner::visit(Force_I *unit) {throw exception();};