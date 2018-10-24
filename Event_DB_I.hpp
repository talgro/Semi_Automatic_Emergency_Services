//
// Created by tal on 20/08/18.
//

#ifndef CODE_CALLSDB_I_HPP
#define CODE_CALLSDB_I_HPP

using namespace std;
#include <vector>
class Manager;
class Event;

class KeyToGetInst_CallDB{
    friend Manager;
    KeyToGetInst_CallDB() = default;
};

class Event_DB_I {
protected:
    static Event_DB_I* CallsDB_singleton;
    virtual void assignEventID(Event*) = 0;
    virtual void addEventToDB(Event*) = 0;

public:
    virtual ~Event_DB_I() = default;
    static Event_DB_I* getInstance(KeyToGetInst_CallDB);
    inline virtual void addNewEvent(Event* event) final {
        assignEventID(event);
        addEventToDB(event);
    };
    virtual void markEventAsInProgressInDB(Event* event) = 0;
    virtual void incReleventUnitsForEvent(Event* event) = 0;
    virtual void closeEvent(Event*) = 0;
    virtual const vector<Event*>* const getOpenCalls() = 0;
    virtual const vector<Event*>* const getArchivedCalls() = 0;
};

#endif //CODE_CALLSDB_I_HPP
