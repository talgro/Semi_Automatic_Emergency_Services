//
// Created by tal on 21/08/18.
//

#ifndef CODE_MEDICALEVENT_HPP
#define CODE_MEDICALEVENT_HPP

class Force_Medical_I;
using namespace std;

class Event_I_Medical{
protected:
    bool _evacuationRequired = false;
    bool _deadBodies = false;
    int _numInjured = 0;

public:
    Event_I_Medical(bool evacuationRequired, bool deadBodies, int numInjured);
    virtual ~Event_I_Medical()=0;
    inline virtual bool isEvacuationRequired(){
        return _evacuationRequired;
    }
    inline virtual void requireEvacuation(bool val){
        _evacuationRequired = val;
    }
    inline virtual bool hasBodies(){
        return _deadBodies;
    }
    inline virtual bool reportBodies(bool val){
        _deadBodies = val;
    }
    inline virtual int numInjured(){
        return _numInjured;
    }
    inline virtual int reportNumInjured(int num){
        _numInjured = num;
    }
    virtual bool isMedicalRequired();
};

#endif //CODE_MEDICALEVENT_HPP