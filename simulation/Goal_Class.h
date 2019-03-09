//
// Created by gadge on 3/7/2019.
//

#ifndef SIMULATION_GOAL_CLASS_H
#define SIMULATION_GOAL_CLASS_H

#include "Line_Class.h"

class Goal_Class : public Line_Class {
private:
    int goal_ID;
public:
    Goal_Class(vector<double> start_input, vector<double> end_input, int line_direction_input, int goal_ID_input) :
    Line_Class(start_input, end_input, line_direction_input){
        goal_ID = goal_ID_input;
    };
    int get_goal_ID(){
        return goal_ID;
    };
};


#endif //SIMULATION_GOAL_CLASS_H
