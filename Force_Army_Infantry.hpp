//
// Created by tal on 01/09/18.
//

#ifndef CODE_FORCE_ARMY_INFANTRY_HPP
#define CODE_FORCE_ARMY_INFANTRY_HPP

#include "Force_Army_I.hpp"

class Force_Army_Infantry : public Force_Army_I{
protected:
    void getToAddress() override;
    void takeCareOfCamouflage() override;
    void killTerroristsBySpecialty() override;

public:
    string getTypeName() override;

    Force_I *clone() override;

    void accept(Forces_Visitor *visitor) override;
};


#endif //CODE_FORCE_ARMY_INFANTRY_HPP
