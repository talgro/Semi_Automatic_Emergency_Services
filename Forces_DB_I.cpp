//
// Created by tal on 27/08/18.
//

#include "Force_I.hpp"
#include "Forces_DB_Default.hpp"

Forces_DB_I* Forces_DB_I::_singleton = nullptr;

Forces_DB_I* Forces_DB_I::getInstance(KeyToGetInst_EF_DB) {
    if (_singleton == nullptr){
        _singleton = new Forces_DB_Default({});
    }
    return _singleton;
}

void Forces_DB_I::addUnitToDB(Force_I *unit) {
    unit->accept(_adderComponent);
}

void Forces_DB_I::eraseUnitFromDB(Force_I *unit) {
    unit->accept(_eraserComponent);
}