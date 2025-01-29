// gameof1d.cpp
//
// This code computes the evolution of a one-dimensional variant of Conway's Game of Life,
// as conceived by Jonathan K. Millen and published in BYTE magazine in December, 1978.
//
// This system is a linear set of cells that are either "alive" or "dead".
// Time in this system progresses in discrete steps.
//
// The state of each cell at the next time step depends on its present
// state and that of its neighbors, in the following way:
//
//   - First, count the number of alive neighbors at most 2 cells away
//   - An alive cell stays alive if that count is 2 or 4, else it dies
//   - A dead cell becomes alive if that count is 2 or 3, else it stays dead.
//
// Since the first two and the last two cells would not have enough neighbours to apply
// this rule, we use cells on the other side as neighbours, i.e., 'periodic boundaries'.
//
// The initial state of this system is constructed with a given fraction of alive
// cells which are (nearly) equally spaced among dead cells.
//
// Without command line arguments, the program computes the time
// evolution for 120 steps, and for each step, prints out a line with
// a representation of the state and fraction of alive cells.
//
// This code is part of assignment 2 of the 2025 Winter PHY1610 course.
//
// Ramses van Zon, 2023-2025, University of Toronto and
// Anuj Chavan, ECE MEng, University of Toronto

#include <iostream>
#include "rarray"
#include "initialize.h"
#include "update.h"
#include "output.h"


// main begins
int main(int argc, char* argv[])
{
    // Set default simulation parameters then accept command line arguments
    int num_cells = 100;
    int num_steps = 120;
    double target_fraction = 0.35;
    try {
        if (argc > 1)
            num_cells = std::stoi(argv[1]);
        if (argc > 2)
            num_steps = std::stoi(argv[2]);
        if (argc > 3)
            target_fraction = std::stod(argv[3]);
    } catch(...) {
        std::cout <<
            "Computes a 1d version of Conway's game of life\n\n"
            "Usage:\n"
            "  gameof1d [-h | --help] | [NUMCELLS [NUMSTEPS [FRACTION]]]\n\n";
        if (std::string(argv[1]) != "-h" and std::string(argv[1]) != "--help") {
            std::cerr << "Error in arguments!\n";
            return 1;
        } else
            return 0;
    }
    
    // Simulation system is just the alive status of each cell
    rvector<bool> alive_status(num_cells);
    
    // initialize cells 
    initialize_cells(alive_status, target_fraction);

    // output cells for time step = 0
    output_cells(alive_status, 0);
    
    // Time evolution loop
    for (int step = 1; step <= num_steps; step++) {
        
        // update cells for each time step
        update_cells(alive_status);
        
        // output cells for each time step
        output_cells(alive_status, step);
    }
} 
// main ends

/*

Assignment 2:

Study the code, make sure you understand what's going on.  Make sure you can compile it, for which you will need to download rarray from https://raw.githubusercontent.com/vanzonr/rarray/refs/heads/main/rarray . Run it and save the initial output to a file so that you can check that the program still work as you start working on it.

Your task is to reorganize ('refactor') this code to be more modular. The aim is to have separate functionalities be implemented in separate functions. I.e., you should

  DONE - Extract the part of the code that first fills the cell array with dead and alive cells, i.e., put that part of the code in a separate initialization function that then gets called from the main function; make sure the program still produce the same output.

  DONE - Make this into a module, i.e., take out that initialization function and put it in a separate .cpp file and create a corresponding header file to be included in the original file.
  
  DONE - Create a Makefile that can build the application.

  DONE - Next, repeat these steps to create and use a module for the part of the code that performs a single time step.

  DONE - Next, repeat these steps to create a module for the output part of the code.

  - Be sure to comment your code.
  
Your submission should consist of all source files, headerfiles, and the Makefile.  It is recommended to put them in a zip file or tar ball (but not rar).
    
*/
