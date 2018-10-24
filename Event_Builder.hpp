//
// Created by tal on 27/08/18.
//

#ifndef CODE_EVENT_BUILDER_HPP
#define CODE_EVENT_BUILDER_HPP

#include <tuple>
#include "Event_Builder_Interfaces.hpp"

class Event_Builder : public Event_Builder_Interfaces{
    friend Event;
private:
    //Event
    const string* _type;
    string _description;
    int _id = -1;
    tuple<string, string> _location;
    //Fire
    bool _numCatsOnTree = false;
    bool _hasFire = false;
    int _numOfTrapped = 0;
    //Medical
    bool _evacuationRequired = false;
    bool _deadBodies = false;
    int _numInjured = 0;
    //Police
    bool _shotsFired = false;
    bool _isDangerous = false;
    int _estimatedNumCriminals = 0;
    //Army
    bool _civiliansAround = false;
    bool _manDown = false;
    int _numTerroristsInvolved = 0;

    static Event_Builder* _singleton;
    Event_Builder() = default;

public:
    static Type_I* getInstance();

    /*
     * Mandatory parameters
     */
    Description_I* setType(const string *type) override{
        _type = type;
        return this;
    }

    Location_I* setDescription(string description) {
        _description = description;
        return this;
    }

    Event_Builder* setLocation(const tuple<string, string> &location) override{
        _location = location;
        return this;
    }

    /*
     * Event_I_Police
     */

    Event_Builder* reportShotsFired(bool val = true){
        _shotsFired = true;
        return this;
    }

    Event_Builder* markAsDangerous(){
        _isDangerous = true;
        return this;
    }

    Event_Builder* reportEstimatedNumCriminals(int n, bool forOverLoading = false){
        _estimatedNumCriminals = n;
        return this;
    }

    /*
     * Event_I_Medical
     */

    Event_Builder* requireEvacuation(){
        _evacuationRequired = true;
        return this;
    }

    Event_Builder* reportBodies(){
        _deadBodies = true;
        return this;
    }

    Event_Builder* reportNumInjured(int n, bool forOverLoading = false){
        _numInjured = n;
        return this;
    }

    /*
     * Event_I_FireFighting
     */

    Event_Builder* requireAerialFireFighting(){
        _numCatsOnTree = true;
        return this;
    }

    Event_Builder* reportFire(){
        _hasFire = true;
        return this;
    }

    Event_Builder* reportNumTrapped(int n, bool forOverLoading = false){
        _numOfTrapped = n;
        return this;
    }

    /*
     * Event_I_Army
     */

    Event_Builder* reportCitizensAround(){
        _civiliansAround = true;
        return this;
    }

    Event_Builder* reportManDown(){
        _manDown = true;
        return this;
    }

    Event_Builder* reportNumTerroristsInvolved(int num, bool forOverLoading = false){
        _numTerroristsInvolved = num;
        return this;
    }

    /*
     * Finish building
     */

    Event* build(){
        return new Event(this);
    }
};


#endif //CODE_EVENT_BUILDER_HPP
