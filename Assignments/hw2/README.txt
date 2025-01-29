Created by: Anuj Chavan, MEng ECE, University of Toronto
PHY1601: Scientific Computing for Physicists, Winter 2025


--------------------------x--------------------------
For original version, navigate to original/
Directory Structure:
-> gameof1d.cpp (main)
-> gameof1d (executable)
-> rarray (dependency)
-> original_output.txt (original_output)

Usage:
In bash run the following commands:
>> g++ -I. gameof1d.cpp -o gameof1d
>> ./gameof1d > original_output.txt
--------------------------x--------------------------


--------------------------x--------------------------
For modularized version, navigate to modularized/
Directory Structure:
-> modularized_gameof1d.cpp (main)
-> modularized_gameof1d.o (executable)
-> modularized_output.txt (modularized_output)
-> rarray (dependency)
-> initialize.cpp (initialization module)
-> initialize.h (initialization header file)
-> initialize.o (initialization executable)
-> update.cpp (updation module)
-> update.h (updation header file)
-> update.o (updation executable)
-> output.cpp (output printing module)
-> output.h (output printing header file)
-> output.o (output printing executable)
-> Makefile (make file)

In terminal, run the following commands: 
(make dependency required run sudo apt install make)
>> make
>> ./modularized_gameof1d > modularized_output.txt
--------------------------x--------------------------

