//
// Created by tal on 21/08/18.
//

#ifndef CODE_POLICEEVENT_HPP
#define CODE_POLICEEVENT_HPP

class Force_Police_I;

using namespace std;

class Event_I_Police{
protected:
    bool _shotsFired = false;
    bool _isDangerous = false;
    int _estimatedNumCriminals = 0;

public:
    Event_I_Police(bool shotsFired, bool isDangerous, int estimatedNumCriminals);
    virtual ~Event_I_Police()=0;
    inline virtual bool shotsFired(){
        return _shotsFired;
    }
    inline virtual void reportShotsFired(){
        _shotsFired = true;
    }
    inline virtual bool isDangerous(){
        return _isDangerous;
    }
    inline virtual void setIsDangerous(bool val){
        _isDangerous = val;
    }
    inline virtual int estimatedNumCriminals(){
        return _estimatedNumCriminals;
    }
    inline virtual void reportEstimatedNumCriminals(int num){
        _estimatedNumCriminals = num;
    }
    virtual bool isPoliceRequired();
};
#endif //CODE_POLICEEVENT_HPP