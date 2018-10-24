//
// Created by tal on 20/08/18.
//

#ifndef CODE_CALLSDB_DEFAULT_HPP
#define CODE_CALLSDB_DEFAULT_HPP

using namespace std;
#include "Event_DB_I.hpp"
#include <unordered_map>

class KeyToCtor_CallDB_def{
    friend Event_DB_I;
    KeyToCtor_CallDB_def() = default;
};

class Event_DB_Default : public Event_DB_I {
protected:
    size_t _availableCodeID = 0;
    vector<Event*> _openCalls;
    vector<pair<Event*, int>*> _inProgressCalls;   //int = num of unit
    vector<Event*> _archivedCalls;

    ~Event_DB_Default();
    void assignEventID(Event*) override;
    void addEventToDB(Event*) override;
    pair<Event*, int>* findInProgressEvent(Event* event);

public:
    Event_DB_Default(KeyToCtor_CallDB_def);
    void closeEvent(Event*) override;
    const vector<Event*>* const getOpenCalls() override;
    const vector<Event *> *const getArchivedCalls() override;
    void markEventAsInProgressInDB(Event *event) override;
    void incReleventUnitsForEvent(Event *event) override;
};

#endif //CODE_CALLSDB_DEFAULT_HPP
