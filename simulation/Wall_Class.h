//
// Created by gadge on 3/7/2019.
//

#ifndef SIMULATION_WALL_CLASS_H
#define SIMULATION_WALL_CLASS_H

#include "Line_Class.h"

class Wall_Class : public Line_Class{
public:
    Wall_Class(vector<double> start_input, vector<double> end_input, int line_direction_input) :
        Line_Class(start_input, end_input, line_direction_input){};
    Wall_Class() : Line_Class(){};


};


#endif //SIMULATION_WALL_CLASS_H
