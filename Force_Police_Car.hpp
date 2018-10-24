//
// Created by tal on 29/08/18.
//

#ifndef CODE_EMERFORCE_POLICE_CAR_HPP
#define CODE_EMERFORCE_POLICE_CAR_HPP

#include "Force_Police_I.hpp"

class Force_Police_Car : public Force_Police_I{
protected:
    void getToAddress() override;
    void performSpecialty() override;

public:
    string getTypeName() override;
    Force_I *clone() override;

    void accept(Forces_Visitor *visitor) override;
};


#endif //CODE_EMERFORCE_POLICE_CAR_HPP
