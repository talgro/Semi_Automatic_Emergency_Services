//
// Created by tal on 22/08/18.
//

#include "Event.hpp"
#include "Event_DB_I.hpp"
#include "Event_Builder.hpp"

Event::Event(Event_Builder* builder) :
        Event_I_Police(builder->_shotsFired, builder->_isDangerous, builder->_estimatedNumCriminals),
        Event_I_Medical(builder->_evacuationRequired, builder->_deadBodies, builder->_numInjured),
        Event_I_FireFighting(builder->_numCatsOnTree, builder->_hasFire, builder->_numOfTrapped),
        Event_I_Army(builder->_civiliansAround, builder->_manDown, builder->_numTerroristsInvolved),
        _type(builder->_type), _description(builder->_description), _id(builder->_id), _location(_location){}

string Event::getDetails() {
    string header = "Event Description: ";
    string eventID = "<ID: " + to_string(_id) + ">, ";
    string eventType = "<Type: " + *_type + ">, ";
    string eventDescription = "";
    if (_description != ""){
        eventDescription = "<Description: " + _description+ ">,";
    }
    else{
        eventDescription = "<Description: Event has no description>";
    }
    string eventDetails = "<Details: " + detailsToString() + ">";
    return header + eventID + eventType + eventDescription + eventDetails;
}

string Event::detailsToString() {
    string details = "";
    if (isMedicalRequired()){
        if (_numInjured > 0){
            details += "num of injured: " + to_string(_numInjured) + ", ";
        }
        if (_deadBodies){
            details += "dead bodies, ";
        }
        if (_evacuationRequired){
            details += "evacuation required, ";
        }
    }
    if (isFireFightinglRequired()){
        if (_numOfTrapped > 0){
            details += "num of trapped: " + to_string(_numOfTrapped) + ", ";
        }
        if (_hasFire){
            details += "fire, ";
        }
        if (_numCatsOnTree > 0){
            details += "evacuation is required, ";
        }
    }
    if (isPoliceRequired()){
        if (_estimatedNumCriminals > 0){
            details += "estimated number of criminals: " + to_string(_estimatedNumCriminals) + ", ";
        }
        if (_isDangerous){
            details += "dangerous, ";
        }
        if (_shotsFired){
            details += "shotes fires,";
        }
    }
    if (isArmyRequired()){
        if (_numTerroristsInvolved > 0){
            details += "estimated number of terrorists: " + to_string(_numTerroristsInvolved) + ", ";
        }
        if (_manDown){
            details += "man down, ";
        }
        if (_civiliansAround){
            details += "civilians around";
        }
    }
    return details;
}