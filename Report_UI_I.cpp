//
// Created by tal on 22/08/18.
//

#include "Report_UI_I.hpp"
#include "Event_DB_I.hpp"
#include "Event.hpp"
#include "Manager.hpp"

void Report_UI_I::reportEmergencyEvent(){
    Type_I* eventForm = Manager::getInstance()->requestEventBuilder();
    Event_Builder* builder = getDetails(eventForm);
    Manager::getInstance()->createEventAndSendToDB(builder);
}