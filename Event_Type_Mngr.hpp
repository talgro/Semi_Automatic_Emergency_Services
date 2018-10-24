//
// Created by tal on 22/08/18.
//

#ifndef CODE_EVENT_TYPE_HPP
#define CODE_EVENT_TYPE_HPP

#include <vector>
#include <unordered_map>
using namespace std;

class Event_Type_Mngr{
private:
    unordered_map<string, size_t> _hashTypes;
    vector<string*> _listTypes;
    Event_Type_Mngr() = default;
    static Event_Type_Mngr* _singleton;

public:
    static Event_Type_Mngr* getInstance();
    ~Event_Type_Mngr();
    inline const string* getTypeByIndex(size_t idx) const{
        return _listTypes.at(idx);
    }
    const string* getTypeByName(string type) const;
    inline int count() const{
        return _listTypes.size();
    }
    bool contains(string type) const;
    void addNewType(string type);
    inline size_t countTypes(){
        return _listTypes.size();
    }
};

#endif //CODE_EVENT_TYPE_HPP