//
// Created by tal on 22/08/18.
//

#include "Report_UI_Console.hpp"
#include <iostream>
#include "Event_Type_Mngr.hpp"
#include "Event.hpp"
#include "Event_Builder.hpp"
#include "Event_DB_I.hpp"

using namespace std;

Event_Builder* Report_UI_Console::getDetails(Type_I* builder) {
    const string* type = askForType();
    string description = askForDescription();
    tuple<string,string> location = askForLocation();
    Event_Builder* eventForm = builder->setType(type)->setDescription(description)->setLocation(location);
    askForOtherDetails(eventForm);
    return eventForm;
}

const string* Report_UI_Console::askForType() {
    const string* type;
    bool validType = false;
    const size_t numTypes = Event_Type_Mngr::getInstance()->countTypes();
    size_t selection = 0;
    while (!validType) {  //means error in selection
        cout << "Emergency call center, what is the emergency?\n Please choose:" << endl;
        for (size_t typeID = 0; typeID < numTypes; ++typeID) {
            const string* typeName = Event_Type_Mngr::getInstance()->getTypeByIndex(typeID);
            cout << to_string(typeID) + " : " + *typeName << endl;
        }
        cout << to_string(numTypes) + " : " + "Report a non-listed event." << endl;  //for non-listed events
        cin >> selection;    //choose
        if (selection >= 0 && selection < numTypes) { //existing setType
            type = Event_Type_Mngr::getInstance()->getTypeByIndex(selection);
            validType = true;
        }
        else if(selection == numTypes){  //Report a non-listed event
            type = reportNonListedEventType();
            validType = true;
        }
        else{
            cout << "invalid choice. Please try again." << endl;
        }
    }
    return type;
}

const string* Report_UI_Console::reportNonListedEventType() {
    string type = "";
    cout << "What is the event?" << endl;
    cin >> type;
    Event_Type_Mngr::getInstance()->addNewType(type);
    return Event_Type_Mngr::getInstance()->getTypeByName(type);
}

tuple<string,string> Report_UI_Console::askForLocation() {
    bool validInput = false;
    string first6 = "";
    string rest6 = "";
    while (!validInput){
        cout << "What is the waypoint of the emergency?\n First 6 digits:" << endl;
        try {
            cin >> first6;
            validInput = true;
        }
        catch(invalid_argument){
            validInput = false;
        }

        cout << "Now the rest of 6 digits:" << endl;
        try {
            cin >> rest6;
            validInput = true;
        }
        catch(invalid_argument){
            validInput = false;
        }
    }
    tuple<string,string> location(first6,rest6);
    return location;
}

string Report_UI_Console::askForDescription() {
    string description = "";
    cout << "Please write as much details as you can." << endl;
    cin.ignore();
    getline(cin, description);
    return description;
}

void Report_UI_Console::askForOtherDetails(Event_Builder* eventBuilder) {
    vector<string> information;
    bool userFinished = false;
    //medical
    information.push_back("Require evacuation");
    information.push_back("Report dead bodies");
    information.push_back("Report num of injured");
    //police
    information.push_back("Report shots fired");
    information.push_back("Report dangerous situation");
    information.push_back("Report estimated num of criminals");
    //fire-fighting
    information.push_back("Require aerial fire-fighting");
    information.push_back("Report fire");
    information.push_back("Report num of trapped");
    //army
    information.push_back("Report citizens around");
    information.push_back("Report man down");
    information.push_back("Report num of terrorists involved");

    //print options
    while (!userFinished){
        cout << "To add more information, please choose an option. To finish press " << to_string(information.size()) << endl;
        for (int infoIdx = 0; infoIdx < information.size(); ++infoIdx) {
            cout << to_string(infoIdx) << " : " << information.at(infoIdx) << endl;
        }
        int selecion = 0;
        cin >> selecion;
        switch (selecion){
            case 0:
                eventBuilder->requireEvacuation();
                break;
            case 1:
                eventBuilder->reportBodies();
                break;
            case 2: {
                size_t injured = 0;
                cout << "How many were injured?" << endl;
                cin >> injured;
                eventBuilder->reportNumInjured(injured);
            }
                break;
            case 3:
                eventBuilder->reportShotsFired();
                break;
            case 4:
                eventBuilder->markAsDangerous();
                break;
            case 5:{
                size_t numCriminals = 0;
                cout << "How many criminals?" << endl;
                cin >> numCriminals;
                eventBuilder->reportEstimatedNumCriminals(numCriminals);
            }
                break;
            case 6:
                eventBuilder->requireAerialFireFighting();
                break;
            case 7:
                eventBuilder->reportFire();
                break;
            case 8:{
                size_t numTrapped = 0;
                cout << "How many trapped?" << endl;
                cin >> numTrapped;
                eventBuilder->reportNumTrapped(numTrapped);
            }
                break;
            case 9:
                eventBuilder->reportCitizensAround();
                break;
            case 10:
                eventBuilder->reportManDown();
                break;
            case 11:{
                size_t numTerrorists = 0;
                cout << "How many terrorists?" << endl;
                cin >> numTerrorists;
                eventBuilder->reportNumTerroristsInvolved(numTerrorists);
            }
                break;
            case 12:
                userFinished = true;
        }
    }

}