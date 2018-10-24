//
// Created by tal on 20/08/18.
//

#ifndef CODE_EVENT_HPP
#define CODE_EVENT_HPP

#include "Event_I_Police.hpp"
#include "Event_I_Medical.hpp"
#include "Event_I_FireFighting.hpp"
#include "Event_I_Army.hpp"
#include "Event_Type_Mngr.hpp"
class Event_Builder;
class Type_I;

using namespace std;

class Event : virtual public Event_I_Police, virtual public Event_I_Medical, virtual public Event_I_FireFighting, virtual public Event_I_Army {
    friend class Event_Builder;

protected:
    Event() = default;
    Event(Event_Builder* builder);
    const string* _type;
    string _description;
    int _id = -1;
    tuple<string, string> _location;

public:
    ~Event() = default;
    string getDetails();
    inline const string* getType() const{
        return _type;
    }
    inline string getDescription() const{
        return _description;
    }
    inline int getID() const{
        return _id;
    }
    inline const tuple<string, string>* getLocation() const{
        return &_location;
    }
    inline void setID(size_t id){
        _id = id;
    }
    string detailsToString();
};

#endif //CODE_EVENT_HPP