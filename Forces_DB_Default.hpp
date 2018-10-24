//
// Created by tal on 27/08/18.
//

#ifndef CODE_EMERFORCE_DB_DEFAULT_HPP
#define CODE_EMERFORCE_DB_DEFAULT_HPP

#include "Forces_DB_I.hpp"

class KeyToCtor{ //only Forces_DB_I can create this class
    friend class Forces_DB_I;
    KeyToCtor() = default;
};

class Forces_DB_Default : public Forces_DB_I{
private:
    class Default_Adder : public Forces_Visitor{
    private:
        Forces_DB_Default* const _father;
        void visit(Force_I *unit) override;

    public:
        Default_Adder(Forces_DB_Default* father);
        void visit(Force_Police_I *unit) override;
        void visit(Force_Medical_I *unit) override;
        void visit(Force_FireFighting_I *unit) override;
        void visit(Force_Army_I *unit) override;
    };
    class Default_Eraser : public Forces_Visitor{
    private:
        Forces_DB_Default* const _father;
        void visit(Force_I *unit) override;

    public:

        Default_Eraser(Forces_DB_Default* father);
        void visit(Force_Police_I *unit) override;
        void visit(Force_Medical_I *unit) override;
        void visit(Force_FireFighting_I *unit) override;
        void visit(Force_Army_I *unit) override;
    };

protected:
    vector<Force_I*> _unitTypes;
    vector<Force_I*> _policeForces;
    vector<Force_I*> _medicalForces;
    vector<Force_I*> _fireForces;
    vector<Force_I*> _armyForces;

public:
    Forces_DB_Default(KeyToCtor);
    void registerNewUnit(Force_I *unitType) override;
    const vector<Force_I *>* const existingUnitTypes() override;
    const vector<Force_I*>* const availablePolice() override;
    const vector<Force_I*>* const availableMedical() override;
    const vector<Force_I*>* const availableFireFighting() override;
    const vector<Force_I*>* const availableArmy() override;
};

#endif //CODE_EMERFORCE_DB_DEFAULT_HPP