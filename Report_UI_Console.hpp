//
// Created by tal on 22/08/18.
//

#ifndef CODE_EMERGENCYCALLINTERFACE_CONSOLE_HPP
#define CODE_EMERGENCYCALLINTERFACE_CONSOLE_HPP

#include "Report_UI_I.hpp"
class Event_Builder;
using namespace std;

class Report_UI_Console : public Report_UI_I{
private:
    const string* askForType();
    const string* reportNonListedEventType() override;
    tuple<string,string> askForLocation();
    string askForDescription();
    void askForOtherDetails(Event_Builder*);
    Event_Builder* getDetails(Type_I* builder) override;
};

#endif //CODE_EMERGENCYCALLINTERFACE_CONSOLE_HPP