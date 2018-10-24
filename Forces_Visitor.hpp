//
// Created by tal on 28/08/18.
//

#ifndef CODE_EMERFORCE_VISITOR_HPP
#define CODE_EMERFORCE_VISITOR_HPP

#include <exception>
using namespace std;

class Force_I;
class Force_Police_I;
class Force_Medical_I;
class Force_FireFighting_I;
class Force_Army_I;

class Forces_Visitor {
public:
    //methods
    virtual ~Forces_Visitor() = default;
    virtual void visit(Force_Police_I* unit) = 0;
    virtual void visit(Force_Medical_I* unit) = 0;
    virtual void visit(Force_FireFighting_I* unit){};// = 0;
    virtual void visit(Force_Army_I* unit) = 0;
    inline virtual void visit(Force_I* unit) = 0;
};


#endif //CODE_EMERFORCE_VISITOR_HPP
