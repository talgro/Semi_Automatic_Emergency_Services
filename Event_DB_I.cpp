//
// Created by tal on 22/08/18.
//

#include "Event_DB_I.hpp"
#include "Event_DB_Default.hpp"
#include "Event.hpp"

Event_DB_I* Event_DB_I::CallsDB_singleton = nullptr;

Event_DB_I* Event_DB_I::getInstance(KeyToGetInst_CallDB) {
    if (Event_DB_I::CallsDB_singleton == nullptr){
        Event_DB_I::CallsDB_singleton = new Event_DB_Default({});
    }
    return CallsDB_singleton;
}