//
// Created by tal on 02/09/18.
//

#include "Event_I_FireFighting.hpp"

Event_I_FireFighting::Event_I_FireFighting(bool numCatsOnTree, bool hasFire, int numOfTrapped)
    : _numCatsOnTree(numCatsOnTree), _hasFire(hasFire), _numOfTrapped(numOfTrapped){}

Event_I_FireFighting::~Event_I_FireFighting(){}   //to make abstract

bool Event_I_FireFighting::isFireFightinglRequired(){
    if (_numOfTrapped > 0 || _hasFire || _numCatsOnTree){
        return true;
    }
    return false;
};