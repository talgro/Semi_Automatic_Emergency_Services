//
// Created by tal on 27/08/18.
//

#ifndef CODE_EMERFORCE_I_HPP
#define CODE_EMERFORCE_I_HPP

#include "Forces_Visitor.hpp"
#include "Forces_DB_I.hpp"
#include <exception>
#include <stdexcept>

class Event;

class Force_I{
public:
    Force_I();
    Force_I(const Force_I& other);
    virtual ~Force_I() = default;
    virtual void getNewMission(Event* event) final;
    virtual void accept(Forces_Visitor* visitor) = 0;
    virtual Force_I* clone() = 0;
    virtual string getTypeName() = 0;
    inline virtual size_t getUnitID() final{
        return _unitID;
    }

protected:
    const size_t _unitID;
    Event* _currEvent;
    struct Exception_NoAvailableUnits : public runtime_error {
    public:
        Exception_NoAvailableUnits(const string forceType)
                : runtime_error("No Available " + forceType + " units") {}
    };
    virtual void setCurrEvent(Event* event) final;
    virtual void controlSituation() = 0;
    virtual void reportSuccess() final;

private:
    static size_t _unitCounter;
};

#endif //CODE_EMERFORCE_I_HPP