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
    Goal_Class(vector<double> start_input, vector<double> end_input,  int goal_ID_input) :
    Line_Class(start_input, end_input, 0){
        goal_ID = goal_ID_input;
    };
    Goal_Class() : Line_Class(){
        goal_ID = 0;
    }
    int get_goal_ID(){
        return goal_ID;
    };
};


#endif //SIMULATION_GOAL_CLASS_H
