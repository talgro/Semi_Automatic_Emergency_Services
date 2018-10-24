//
// Created by tal on 01/09/18.
//

#ifndef CODE_FORCE_FIREFIGHTERS_TRUCK_HPP
#define CODE_FORCE_FIREFIGHTERS_TRUCK_HPP

#include "Force_FireFighting_I.hpp"

class Force_FireFighters_FireTruck : public Force_FireFighting_I{
protected:
    void getToAddress() override;
    void performSpecialty() override;

public:
    string getTypeName() override;
    Force_I *clone() override;

    void accept(Forces_Visitor *visitor) override;
};


#endif //CODE_FORCE_FIREFIGHTERS_TRUCK_HPP
