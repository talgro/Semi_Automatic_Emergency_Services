//
// Created by tal on 22/08/18.
//

#include "Event_Type_Mngr.hpp"
using namespace std;

Event_Type_Mngr* Event_Type_Mngr::_singleton = nullptr;

Event_Type_Mngr* Event_Type_Mngr::getInstance() {
    if (_singleton == nullptr){
        _singleton = new Event_Type_Mngr();
    }
    return _singleton;
}

Event_Type_Mngr::~Event_Type_Mngr() {
    for (auto eventType : _listTypes){
        delete eventType;
    }
}

const string* Event_Type_Mngr::getTypeByName(string type) const {
    size_t idx = _hashTypes.find(type)->second;
    return _listTypes.at(idx);
}

bool Event_Type_Mngr::contains(string type) const{
    if (_hashTypes.find(type) == _hashTypes.end()){
        return false;
    }
    return true;
}

void Event_Type_Mngr::addNewType(string typeName) {
    if (!contains(typeName)) {
        string* newType = new string(typeName);
        _listTypes.push_back(newType);
        _hashTypes.insert({typeName, _listTypes.size()-1});
    }
}
