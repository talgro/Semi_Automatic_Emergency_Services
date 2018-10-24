**About
--------
As my Final project of Design-Patterns course during my studies of Computer Science BS.c, I decided to plan and build a semi automatic emegency services call center.
In the planning (UML is added) I put an emphasis on abstraction and object-oriented design.
In addidtion, I tried to use as much designs-patterns as I could for practice.


**What it actually does
------------------------
The system gets emergency events through different interfaces, records them in a database, and gives situation overview for the system manager.


**System Archithcture
----------------------
We can seperate the classes into 5 components:
-System managment interfaces
-Event reporting interfaces
-Events database
-Available emergency forces database
-Emergency forces Types
The system archithcture enables abstraction of these core components.
For example, the design supports any database type chosen be the system admin. Another example is that it is possible to add emergency forces.


**Design-Pattern included
--------------------------
-Passkey
-Singleton
-Facade
-Builder
-Visitor
-Factory method
