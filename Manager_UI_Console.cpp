//
// Created by tal on 01/09/18.
//

#include <iostream>
#include "Manager_UI_Console.hpp"
#include "Force_I.hpp"
#include "Manager.hpp"
#include "Event.hpp"

void Manager_UI_Console::menu() {
    int choice = 0;
    while (true) {
        cout << "---------------------------" << endl;
        cout << "Manager Menu" << endl;
        cout << "---------------------------" << endl;
        cout << "What do you want to do?" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Add a unit to the DB" << endl;
        cout << "2. Erase a unit from the DB" << endl;
        cout << "3. View available emergency forces" << endl;
        cout << "4. Assign a unit for an event" << endl;
        cout << "5. View open events" << endl;
        cout << "6. view archived events" << endl;

        cout << "Type your choice number" << endl;
        cin >> choice;

        if (choice < 0 || choice > 6) {
            cout << "Wrong choice number! Please try again" << endl;
        }
        else {
            switch (choice) {
                case 0:
                    return;
                case 1:
                    addUnitToDB();
                    break;
                case 2:
                    eraseUnit();
                    break;
                case 3:
                    viewAvailableEmergencyForces();
                    break;
                case 4:
                    automaticallyAssignUnitForEvent();
                    break;
                case 5:
                    viewOpenEvents();
                    break;
                case 6:
                    viewArchivedEvents();
                    break;
            }
        }
    }
}

void Manager_UI_Console::addUnitToDB() {
    const int typeIndex = chooseUnitTypeFromExisting();
    Force_I* newUnit = createUnitFromExisting(typeIndex);
    Manager::getInstance()->addUnitToDB(newUnit);
}

int Manager_UI_Console::chooseUnitTypeFromExisting() {
    const vector<Force_I*>* existingUnitTypes = Manager::getInstance()->existingUnitTypes();
    viewUnitTypes(existingUnitTypes);
    const int unitTypeIdx = askUserForUnitType();
    return unitTypeIdx;
}

Force_I *Manager_UI_Console::createUnitFromExisting(int typeIndex) {
    Force_I* selectedUnit = Manager::getInstance()->existingUnitTypes()->at(typeIndex);
    return Manager::getInstance()->newUnitFromType(selectedUnit);
}

void Manager_UI_Console::viewUnitTypes(const vector<Force_I*> *unitTypesList) {
    cout << "---------------------------" << endl;
    cout << "Unit Types:" << endl;
    cout << "---------------------------" << endl;
    for (int unitIdx = 0; unitIdx < unitTypesList->size(); ++unitIdx) {
        cout << "Index: " << to_string(unitIdx) << " , Type: " << unitTypesList->at(unitIdx)->getTypeName() << endl;
    }
}

int Manager_UI_Console::askUserForUnitType() {
    int selection = -1;
    while (selection < 0 || selection > 3){
        cout << "Please select user type to create by index." << endl;
        cin >> selection;
    }
    return selection;
}

void Manager_UI_Console::eraseUnit() {
    viewAvailableEmergencyForces();
    const size_t unitID = chooseUnitToErase();
    Force_I* const unit = findUnit(unitID);
    Manager::getInstance()->eraseUnitFromDB(unit);
}

size_t Manager_UI_Console::chooseUnitToErase(){
    int id = 0;
    cout << "Which unit would you like to erase? Please type an ID" << endl;
    cin >> id;
    return id;
}

Force_I* Manager_UI_Console::findUnit(size_t unitID){
    vector<const vector<Force_I*>*> unitLists(4);
    unitLists.at(0) = Manager::getInstance()->getAvailableForces_Medical();
    unitLists.at(1) = Manager::getInstance()->getAvailableForces_Army();
    unitLists.at(2) = Manager::getInstance()->getAvailableForces_Fire();
    unitLists.at(3) = Manager::getInstance()->getAvailableForces_Police();

    for (auto unitList : unitLists){
        for (auto unit : *unitList){
            if (unit->getUnitID() == unitID){
                return unit;
            }
        }
    }
}

void Manager_UI_Console::viewAvailableEmergencyForces() {
    cout << "---------------------------" << endl;
    cout << "Available Emergency Forces:" << endl;
    cout << "---------------------------" << endl;

    vector<string> unitListsNames(4);
    vector<const vector<Force_I*>*> unitLists(4);

    unitLists.at(0) = Manager::getInstance()->getAvailableForces_Medical();
    unitListsNames.at(0) = "Medical";

    unitLists.at(1) = Manager::getInstance()->getAvailableForces_Army();
    unitListsNames.at(1) = "Army";

    unitLists.at(2) = Manager::getInstance()->getAvailableForces_Fire();
    unitListsNames.at(2) = "Fire-Fighters";

    unitLists.at(3) = Manager::getInstance()->getAvailableForces_Police();
    unitListsNames.at(3) = "Police";

    for (int forceIdx = 0; forceIdx < unitLists.size(); ++forceIdx) {
        cout << unitListsNames.at(forceIdx) << ":" << endl;
        const vector<Force_I*>* unitList = unitLists.at(forceIdx);
        int unitCounter = 0;
        for (auto unit : *unitList){
            ++unitCounter;
            cout << to_string(forceIdx*4+unitCounter) << ". " << unit->getTypeName() << ", ID: " << unit->getUnitID() << endl;
        }
    }
}

void Manager_UI_Console::automaticallyAssignUnitForEvent() {
    viewOpenEvents();
    const int eventID = chooseEventToAssign();
    if (eventID > -1){
        Event* const event = findEvent(eventID);
        Manager::getInstance()->assignUnitForEvent(event);
    }
}

void Manager_UI_Console::viewOpenEvents() {
    printEvents(Manager::getInstance()->getOpenCalls());
}

int Manager_UI_Console::chooseEventToAssign() {
    int id = 0;
    cout << "To which event would you like to assign a unit? Please type an ID. Choose -1 to exit." << endl;
    cin >> id;
    return id;
}

Event* Manager_UI_Console::findEvent(int eventID){
    const vector<Event*>* eventsList = Manager::getInstance()->getOpenCalls();
    for (auto event : *eventsList){
        if (event->getID() == eventID){
            return event;
        }
    }
    throw Exception_EventIdNotExists(eventID);
}

void Manager_UI_Console::printEvents(const vector<Event *> *listOfEvents) {
    cout << "---------------------------" << endl;
    cout << "Events:" << endl;
    cout << "---------------------------" << endl;
    for (int eventIdx = 0; eventIdx < listOfEvents->size(); ++eventIdx) {
        cout << listOfEvents->at(eventIdx)->getDetails() << endl;
    }
}

void Manager_UI_Console::viewArchivedEvents() {
    printEvents(Manager::getInstance()->getArchivedCalls());
}
