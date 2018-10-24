//
// Created by tal on 22/08/18.
//

#ifndef CODE_EVENT_FIREFIGHTING_HPP
#define CODE_EVENT_FIREFIGHTING_HPP

class Force_FireFighting_I;
using namespace std;

class Event_I_FireFighting{
protected:
    bool _numCatsOnTree = false;
    bool _hasFire = false;
    int _numOfTrapped = 0;

public:
    Event_I_FireFighting(bool numCatsOnTree, bool hasFire, int numOfTrapped);
    virtual ~Event_I_FireFighting()=0;
    inline virtual int numOfCatsOnTree(){
        return _numCatsOnTree;
    }
    inline virtual bool requireAerialFireFighting(bool val){
        _numCatsOnTree = val;
    }
    inline virtual bool hasFire(){
        return _hasFire;
    }
    inline virtual bool reportFire(bool val){
        _hasFire = val;
    }
    inline virtual int numOfTrapped(){
        return _numOfTrapped;
    }
    inline virtual int reportNumTrapped(int num){
        _numOfTrapped = num;
    }
    virtual bool isFireFightinglRequired();
};

#endif //CODE_EVENT_FIREFIGHTING_HPP