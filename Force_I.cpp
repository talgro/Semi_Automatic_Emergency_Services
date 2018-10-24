//
// Created by tal on 27/08/18.
//

#include "Force_I.hpp"
#include "Manager.hpp"
#include "Event.hpp"

size_t Force_I::_unitCounter = 0;

Force_I::Force_I(const Force_I &other)
    : _unitID(_unitCounter++){}

Force_I::Force_I()
    : _unitID(_unitCounter++){}

void Force_I::getNewMission(Event* event) {
    setCurrEvent(event);
    controlSituation();
    reportSuccess();
}

void Force_I::setCurrEvent(Event *event) {
    _currEvent = event;
}

void Force_I::reportSuccess() {
    Manager::getInstance()->closeEvent(_currEvent);
    Manager::getInstance()->addUnitToDB(this);
}