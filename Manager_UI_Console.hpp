//
// Created by tal on 01/09/18.
//

#ifndef CODE_MANAGER_UI_CONSOLE_HPP
#define CODE_MANAGER_UI_CONSOLE_HPP

#include "Manager_UI_I.hpp"

class Manager_UI_Console : public Manager_UI_I{
public:
    virtual void menu();

private:
    virtual void addUnitToDB() override;
    int chooseUnitTypeFromExisting();
    Force_I* createUnitFromExisting(int typeIndex);
    void viewUnitTypes(const vector<Force_I*>*);
    int askUserForUnitType();
    virtual void eraseUnit() override;
    void viewAvailableEmergencyForces() override;
    size_t chooseUnitToErase();
    Force_I* findUnit(size_t unitID);
    void automaticallyAssignUnitForEvent() override;
    void viewOpenEvents() override;
    void printEvents(const vector<Event *> *listOfEvents);
    int chooseEventToAssign();
    Event* findEvent(int eventID);
    void viewArchivedEvents() override;
};


#endif //CODE_MANAGER_UI_CONSOLE_HPP
