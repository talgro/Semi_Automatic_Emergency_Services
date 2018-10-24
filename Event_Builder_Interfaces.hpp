//
// Created by tal on 27/08/18.
//

#ifndef CODE_EVENT_BUILDER_INTERFACES_HPP
#define CODE_EVENT_BUILDER_INTERFACES_HPP

#include <string>
#include "Event.hpp"

class Event_Builder;
using namespace std;

struct Location_I{
    virtual Event_Builder* setLocation(const tuple<string, string>& location) = 0;
};

struct Description_I{
    virtual Location_I* setDescription(string description) = 0;
};

struct Type_I{
    virtual Description_I* setType(const string *type) = 0;
};

class Event_Builder_Interfaces : public Location_I, public Description_I, public Type_I{

};
#endif //CODE_EVENT_BUILDER_INTERFACES_HPP
