//
// Created by tal on 27/08/18.
//

#ifndef CODE_EMERGENCYMANAGER_HPP
#define CODE_EMERGENCYMANAGER_HPP

#include "Forces_Visitor.hpp"
#include <vector>
#include <unordered_map>
class Event_Builder;
class Force_I;
class Type_I;
class Event;

class Manager {
private:
    static Manager* _singleton;
    Manager() = default;

    class Assigner : public Forces_Visitor{
    private:
        Event* _currEvent;
        bool considerPolice(Event* event);
        bool considerMedical(Event* event);
        bool considerFireFighting(Event* event);
        bool considerArmy(Event* event);

    public:
        void visit(Force_I *unit) override;

    public:
        void assignUnitForEvent(Event* event);
        void visit(Force_Police_I *unit) override;
        void visit(Force_Medical_I *unit) override;
        void visit(Force_FireFighting_I *unit) override;
        void visit(Force_Army_I *unit) override;
    };
    Assigner _assignerComponent;
    
public:
    static Manager* getInstance();
    //for Report-UI
    Type_I* requestEventBuilder();
    void createEventAndSendToDB(Event_Builder* eventBuilder);
    //for Manager-UI
    ////forces
    void registerUnitType(Force_I* unit);
    void addUnitToDB(Force_I *unit);
    void eraseUnitFromDB(Force_I *unit);
    Force_I* newUnitFromType(Force_I* unit);
    ////events
    void assignUnitForEvent(Event* event);
    void markEventAsInProgressInDB(Event *event);
    void incReleventUnitsForEvent(Event *event);
    void closeEvent(Event*);
    //getters
    const vector<Force_I*>* const existingUnitTypes();
    const vector<Event*>* const getOpenCalls() const;
    const vector<Event*>* const getArchivedCalls() const;
    const vector<Force_I*>* const getAvailableForces_Police();
    const vector<Force_I*>* const getAvailableForces_Medical();
    const vector<Force_I*>* const getAvailableForces_Fire();
    const vector<Force_I*>* const getAvailableForces_Army();
};

#endif //CODE_EMERGENCYMANAGER_HPP