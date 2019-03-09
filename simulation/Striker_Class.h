//
// Created by gadge on 3/7/2019.
//

#ifndef SIMULATION_STRIKER_CLASS_H
#define SIMULATION_STRIKER_CLASS_H
#include "Goal_Class.h"
#include "Line_Class.h"
#include "Wall_Class.h"
#include "passing_structures.h"
#include "Circle_Class.h"

class Striker_Class : public Circle_Class{
private:
    int striker_ID;
public:
    int get_striker_ID(){ return striker_ID;}
    Striker_Class(double mass_input, double radius_input, double update_time_input, vector<double> position_input, int striker_ID_input);
    void propose_new_position(double update_time, vector<double> velocity);
};


#endif //SIMULATION_STRIKER_CLASS_H
