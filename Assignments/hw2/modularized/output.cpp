#include <iostream>
#include "output.h"
#include "rarray"

/*
// modularized function definition
// output time step, alive of cells, and fraction of alive cells
char alive_char = 'O';
char dead_char = ' ';
double fraction = std::count(alive_status.begin(), alive_status.end(), true)
                    / double(alive_status.size());
std::string string_represention(alive_status.size(), ' ');
for (int i = 0; i < alive_status.size(); i++)
    if (alive_status[i])
        string_represention[i] = alive_char;
    else
        string_represention[i] = dead_char;
std::cout << 0 << "\t" << string_represention << " " << fraction << "\n";

*/
void output_cells(const rvector<bool>& alive_status, int step) {
    char alive_char = 'O';
    char dead_char = ' ';

    // fraction of cells alive
    double fraction = std::count(alive_status.begin(), alive_status.end(), true)
                        / double(alive_status.size());
    
    // convert to a string and print out
    std::string string_represention(alive_status.size(), ' ');
    for (int i = 0; i < alive_status.size(); i++)
        if (alive_status[i])
            string_represention[i] = alive_char;
        else
            string_represention[i] = dead_char;
    
    std::cout << step << "\t" << string_represention << " " << fraction << "\n";
}
