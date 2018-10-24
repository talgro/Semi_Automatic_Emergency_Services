//
// Created by tal on 27/08/18.
//

#ifndef CODE_EMERFORCE_MEDICAL_HPP
#define CODE_EMERFORCE_MEDICAL_HPP

#include "Force_I.hpp"

class Force_Medical_I : public Force_I{
protected:
    virtual void controlSituation() override final;
    virtual void getToAddress() = 0;
    virtual void sortPatientsByUrgency();
    virtual void giveFirstAid();
    virtual void performSpecialty() = 0;
    virtual void evacuateToHospital() = 0;

public:
    virtual ~Force_Medical_I() = default;
    const static Force_I::Exception_NoAvailableUnits _NoAvailableMedicalUnits;
};


#endif //CODE_EMERFORCE_MEDICAL_HPP
