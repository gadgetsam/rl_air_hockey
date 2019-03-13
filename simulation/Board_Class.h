//
// Created by gadge on 3/7/2019.
//

#ifndef SIMULATION_BOARD_CLASS_H
#define SIMULATION_BOARD_CLASS_H

#include <iostream>
#include "Goal_Class.h"
#include "Line_Class.h"
#include "Puck_Class.h"
#include "Striker_Class.h"
#include "Wall_Class.h"
#include "passing_structures.h"
#include "Circle_Class.h"

class Board_Class {
private:
    Goal_Class goals[2];
    Wall_Class walls[4];
    Striker_Class strikers[2];
    Puck_Class puck;
    double update_time = 1.0/30.0; //Designed to run at 30 frames a second
public:
    Board_Class(double update_time, double puck_mass, double friction, double striker_mass);
    Update_Return update(double striker_1_x_velocity, double striker_1_y_velocity, double striker_2_x_velocity, double striker_2_y_velocity);
    // update function runs an update of the simulation it takes the input of the velocities of the two strikers and
    // then returns the positions of all elements on the board
    void reset(); // resets board to original state
};


#endif //SIMULATION_BOARD_CLASS_H
