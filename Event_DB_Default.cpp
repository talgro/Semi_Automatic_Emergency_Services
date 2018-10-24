//
// Created by tal on 20/08/18.
//

#include <algorithm>
#include "Event_DB_Default.hpp"
#include "Event.hpp"

using namespace std;

void Event_DB_Default::assignEventID(Event* event) {
    event->setID(_availableCodeID++);
}

void Event_DB_Default::addEventToDB(Event* event) {
    _openCalls.push_back (event);
}

Event_DB_Default::~Event_DB_Default() {
    for (auto event : _openCalls){
        delete event;
    }

    for (pair<Event*, int>* eventTuple : _inProgressCalls){
        Event* event = eventTuple->first;
        delete event;
        delete eventTuple;
    }

    for (auto event : _archivedCalls){
        delete event;
    }
}

Event_DB_Default::Event_DB_Default(KeyToCtor_CallDB_def) {}

void Event_DB_Default::closeEvent(Event* event) {
    pair<Event*, int>* inProgressEvent = findInProgressEvent(event);
    inProgressEvent->second--;
    if (inProgressEvent->second == 0){
        auto it = find(_inProgressCalls.begin(), _inProgressCalls.end(), inProgressEvent);
        _inProgressCalls.erase(it);
        _archivedCalls.push_back(event);
    }
}

void Event_DB_Default::incReleventUnitsForEvent(Event *event) {
    pair<Event*, int>* inProgressEvent = findInProgressEvent(event);
    inProgressEvent->second++;
}

pair<Event*, int>* Event_DB_Default::findInProgressEvent(Event *event) {
    for (int eventIdx = 0; eventIdx < _inProgressCalls.size(); ++eventIdx) {
        pair<Event*, int>* inProgressEvent = _inProgressCalls.at(eventIdx);
        if (inProgressEvent->first == event){
            return inProgressEvent;
        }
    }
}


void Event_DB_Default::markEventAsInProgressInDB(Event *event) {
    auto it = find(_openCalls.begin(), _openCalls.end(), event);
    if (it != _openCalls.end()){
        _openCalls.erase(it);
    }
    _inProgressCalls.push_back(new pair<Event*, int>(event, 0));
}

const vector<Event*>* const Event_DB_Default::getOpenCalls() {
    return &_openCalls;
}

const vector<Event *> *const Event_DB_Default::getArchivedCalls() {
    return &_archivedCalls;
}
