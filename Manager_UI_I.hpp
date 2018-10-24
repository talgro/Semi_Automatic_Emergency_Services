//
// Created by tal on 01/09/18.
//

#ifndef CODE_MANAGER_UI_I_HPP
#define CODE_MANAGER_UI_I_HPP

//#include "Manager.hpp"

using namespace std;
#include <string>
#include <vector>
#include <stdexcept>

class Force_I;
class Event;

class Manager_UI_I {
public:
    virtual ~Manager_UI_I() = default;
    virtual void menu() = 0;

protected:
    virtual void addUnitToDB() = 0;
    virtual void eraseUnit() = 0;
    virtual void viewAvailableEmergencyForces() = 0;
    virtual void automaticallyAssignUnitForEvent() = 0;
    virtual void viewOpenEvents() = 0;
    virtual void viewArchivedEvents() = 0;

    struct Exception_EventIdNotExists : public runtime_error {
    public:
        Exception_EventIdNotExists(const int eventID)
                : runtime_error("No such event ID: " + to_string(eventID)) {}
    };
};


#endif //CODE_MANAGER_UI_I_HPP
