//
// Created by tal on 22/08/18.
//

#ifndef CODE_EMERGENCYCALL_I_HPP
#define CODE_EMERGENCYCALL_I_HPP

#include <vector>
#include "string"
class Event;
class Event_Builder;
class Type_I;

using namespace std;

class Report_UI_I {
protected:
    virtual const string* reportNonListedEventType() = 0;
    virtual Event_Builder* getDetails(Type_I* builder) = 0;

public:
    virtual ~Report_UI_I() = default;
    virtual void reportEmergencyEvent() final;
};

#endif //CODE_EMERGENCYCALL_I_HPP