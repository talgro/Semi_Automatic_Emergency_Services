//
// Created by tal on 27/08/18.
//

#ifndef CODE_EMERFORCE_DB_I_HPP
#define CODE_EMERFORCE_DB_I_HPP

#include <vector>
#include "Forces_Visitor.hpp"
class Force_I;
class Force_Police_I;
class Force_Medical_I;
class Force_FireFighting_I;
class Force_Army_I;
class Manager;
using namespace std;

class KeyToGetInst_EF_DB{
    friend Manager;
    KeyToGetInst_EF_DB() = default;
};

class Forces_DB_I{
protected:
    static Forces_DB_I* _singleton;
    Forces_Visitor* _adderComponent;
    Forces_Visitor* _eraserComponent;

public:
    //methods
    virtual ~Forces_DB_I() = default;
    static Forces_DB_I* getInstance(KeyToGetInst_EF_DB);
    virtual void registerNewUnit(Force_I* force) = 0;
    virtual const vector<Force_I*>* const existingUnitTypes() = 0;
    virtual const vector<Force_I*>* const availablePolice() = 0;
    virtual const vector<Force_I*>* const availableMedical() = 0;
    virtual const vector<Force_I*>* const availableFireFighting() = 0;
    virtual const vector<Force_I*>* const availableArmy() = 0;
    virtual void addUnitToDB(Force_I *unit) final;
    virtual void eraseUnitFromDB(Force_I *unit) final;
};

#endif //CODE_EMERFORCE_DB_I_HPP