//
// Created by tal on 27/08/18.
//

#include "Event_Builder.hpp"

Event_Builder* Event_Builder::_singleton = nullptr;

Type_I* Event_Builder::getInstance() {
    if (_singleton != nullptr){
        delete _singleton;   //to reset data members
    }
    _singleton = new Event_Builder();
    return _singleton;
}