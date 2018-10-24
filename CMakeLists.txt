cmake_minimum_required(VERSION 3.12)
project(Code)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Code main.cpp Event_DB_I.hpp Event_DB_Default.cpp Event_DB_Default.hpp Event.hpp Event_I_Police.hpp Event_I_FireFighting.hpp Event_I_Army.hpp Event_Type_Mngr.hpp Event_Type_Mngr.cpp Event_DB_I.cpp Event.cpp Report_UI_I.cpp Report_UI_I.hpp Report_UI_Console.cpp Report_UI_Console.hpp Event_Builder.cpp Event_Builder.hpp Event_Builder_Interfaces.hpp Manager.cpp Manager.hpp Forces_DB_I.cpp Forces_DB_I.hpp Forces_DB_Default.cpp Forces_DB_Default.hpp Force_Police_I.cpp Force_Police_I.hpp Force_Army_I.cpp Force_Army_I.hpp Force_Medical_I.cpp Force_Medical_I.hpp Force_FireFighting_I.cpp Force_FireFighting_I.hpp Force_I.cpp Force_I.hpp Forces_Visitor.hpp Force_Police_Car.cpp Force_Police_Car.hpp Force_Medical_Ambulance.cpp Force_Medical_Ambulance.hpp Force_FireFighters_FireTruck.cpp Force_FireFighters_FireTruck.hpp Force_Army_Infantry.cpp Force_Army_Infantry.hpp Manager_UI_I.hpp Manager_UI_Console.cpp Manager_UI_Console.hpp Event_I_Police.cpp Event_I_Medical.cpp Event_I_FireFighting.cpp Event_I_Army.cpp)