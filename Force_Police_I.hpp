//
// Created by tal on 27/08/18.
//

#ifndef CODE_EMERFORCE_POLICE_HPP
#define CODE_EMERFORCE_POLICE_HPP

#include "Force_I.hpp"

class Force_Police_I : public Force_I {
protected:
    virtual void controlSituation() override final;
    virtual void getToAddress() = 0;
    virtual void getCrowdAway();
    virtual void weaponsOut();
    virtual void loadBullet();
    virtual void beCareful();
    virtual void warnCriminals();
    virtual void performSpecialty() = 0;
    virtual void killCriminals();
    virtual void falseAlarm();

public:
    virtual Force_I *clone() = 0;
    virtual string getTypeName() = 0;
    static Exception_NoAvailableUnits _NoAvailablePoliceUnits;
};

#endif //CODE_EMERFORCE_POLICE_HPP
