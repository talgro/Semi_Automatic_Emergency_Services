//
// Created by tal on 01/09/18.
//

#ifndef CODE_FORCE_MEDICAL_AMBULANCE_HPP
#define CODE_FORCE_MEDICAL_AMBULANCE_HPP

#include "Force_Medical_I.hpp"

class Force_Medical_Ambulance : public Force_Medical_I{
protected:
    void getToAddress() override;
    void performSpecialty() override;
    void evacuateToHospital() override;

public:
    string getTypeName() override;
    Force_I *clone() override;

    void accept(Forces_Visitor *visitor) override;
};


#endif //CODE_FORCE_MEDICAL_AMBULANCE_HPP
