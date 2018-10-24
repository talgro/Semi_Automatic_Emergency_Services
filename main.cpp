#include <iostream>
#include <vector>

#include "Manager.hpp"
#include "Manager_UI_Console.hpp"
#include "Report_UI_Console.hpp"
#include "Force_FireFighters_FireTruck.hpp"
#include "Force_Medical_Ambulance.hpp"
#include "Force_Army_Infantry.hpp"
#include "Force_Police_Car.hpp"
#include <thread>

using namespace std;

void registerUnitTypesAndAddToDB(){
    Force_FireFighters_FireTruck fireTruck;
    Force_Medical_Ambulance ambulance;
    Force_Police_Car policeCar;
    Force_Army_Infantry infantry;

    Manager::getInstance()->registerUnitType(&fireTruck);
    Manager::getInstance()->registerUnitType(&ambulance);
    Manager::getInstance()->registerUnitType(&policeCar);
    Manager::getInstance()->registerUnitType(&infantry);
}

void manager(){
    Manager_UI_Console managerConsole;
    managerConsole.menu();
}

void report(){
    Report_UI_Console reportConsole;
    reportConsole.reportEmergencyEvent();
}

int main() {
    registerUnitTypesAndAddToDB();

    Manager_UI_Console managerConsole;
    Report_UI_Console reportConsole;

    while (true){
        managerConsole.menu();
        reportConsole.reportEmergencyEvent();
    }
}