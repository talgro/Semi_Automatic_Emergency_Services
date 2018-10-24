//
// Created by tal on 27/08/18.
//

#ifndef CODE_EMERFORCE_ARMY_HPP
#define CODE_EMERFORCE_ARMY_HPP

#include "Force_I.hpp"
class Forces_Visitor;

class Force_Army_I : public Force_I{
protected:
    virtual void controlSituation() override final;
    virtual void getToAddress() = 0;
    virtual void takeCareOfCamouflage() = 0;
    virtual void moveCiviliansAway();
    virtual void evacuateBody();
    virtual void killTerroristsBySpecialty() = 0;

public:
    virtual ~Force_Army_I() = default;
    static Force_I::Exception_NoAvailableUnits _NoAvailableArmyUnits;
};

#endif //CODE_EMERFORCE_ARMY_HPP
