//
// Created by tal on 27/08/18.
//

#ifndef CODE_EMERFORCE_FIRE_HPP
#define CODE_EMERFORCE_FIRE_HPP

#include "Force_I.hpp"

class Force_FireFighting_I : public Force_I{
protected:
    virtual void controlSituation() override final;
    virtual void getToAddress() = 0;
    virtual void recognizeFireSource();
    virtual void rescueCats();
    virtual void rescueTrapped();
    virtual void performSpecialty() = 0;

public:
    static Force_I::Exception_NoAvailableUnits _NoAvailableFireFightingUnits;
};

#endif //CODE_EMERFORCE_FIRE_HPP