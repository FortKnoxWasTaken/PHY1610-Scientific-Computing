#include "initialize.h"

/*
// modularized function definition 
// fill cells such that the fraction of alive cells is roughly target_fraction
    double fill = 0.0;
    for (bool& alive: alive_status) {
        fill += target_fraction;
        if (fill >= 1.0) {
            alive = true;
            fill -= 1.0;
        } else {
            alive = false;
        }
    }

*/
void initialize_cells(rvector<bool>& alive_status, double target_fraction) {
    double fill = 0.0;
    for (bool& alive : alive_status) {
        fill += target_fraction;
        if (fill >= 1.0) {
            alive = true;
            fill -= 1.0;
        } else {
            alive = false;
        }
    }
}
