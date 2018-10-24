//
// Created by tal on 22/08/18.
//

#ifndef CODE_EVENT_ARMY_HPP
#define CODE_EVENT_ARMY_HPP

class Force_Army_I;
using namespace std;

class Event_I_Army{
protected:
    bool _civiliansAround = false;
    bool _manDown = false;
    int _numTerroristsInvolved = 0;

public:
    Event_I_Army(bool civiliansAround, bool manDown, int numTerroristsInvolved);
    virtual ~Event_I_Army()=0;
    inline virtual bool civiliansAround(){
        return _civiliansAround;
    }
    inline virtual void reportCitizensAround(bool val){
        _civiliansAround = val;
    }
    inline virtual bool manDown(){
        return _manDown;
    }
    inline virtual bool reportManDown(bool val){
        _manDown = val;
    }
    inline virtual int numTerroristsInvolved(){
        return _numTerroristsInvolved;
    }
    inline virtual int reportNumTerroristsInvolved(int num){
        _numTerroristsInvolved = num;
    }
    virtual bool isArmyRequired();
};

#endif //CODE_EVENT_ARMY_HPP