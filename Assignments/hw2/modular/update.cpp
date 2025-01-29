#include "update.h"
#include "rarray"


// determine the next alive status of the cell at location index' within the linear set of cells 'cell_alive', based on the alive status of its neighboring cells.
bool is_cell_alive_next(const rvector<bool>& cell_alive, int index)
{
    int num_cells = cell_alive.size();
    int alive_neighbours = 0;
    for (int offset = -2; offset <= 2; offset++)
        if (offset != 0 and cell_alive[(index+offset+num_cells)%num_cells]) // modulus (%) enforces periodic boundary conditions
            alive_neighbours++;
    if (cell_alive[index] and
        (alive_neighbours == 2 or alive_neighbours == 4))
        return true;
    else if (not cell_alive[index] and
             (alive_neighbours == 2 or alive_neighbours == 3))
        return true;
    else
        return false;
}


/*
// modularized function definition 
// update cells
rvector<bool> next_alive_status(alive_status.size());
for (int i = 0; i < alive_status.size(); i++) 
    next_alive_status[i] = is_cell_alive_next(alive_status, i);
// Make next status the current one using swap, which avoids a copy
std::swap(alive_status, next_alive_status);  

*/
// function to update the cells for one time step
void update_cells(rvector<bool>& alive_status) {
    rvector<bool> next_alive_status(alive_status.size());
    for (int i = 0; i < alive_status.size(); i++) {
        next_alive_status[i] = is_cell_alive_next(alive_status, i);
    }
    // swap the old status with the new status
    std::swap(alive_status, next_alive_status);
}
