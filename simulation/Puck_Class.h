//
// Created by gadge on 3/7/2019.
//

#ifndef SIMULATION_PUCK_CLASS_H
#define SIMULATION_PUCK_CLASS_H
#include <iostream>
#include "Goal_Class.h"
#include "Line_Class.h"

#include "Wall_Class.h"
#include "passing_structures.h"
#include "Circle_Class.h"


class Puck_Class : public Circle_Class{
private:
    double friction;
    double update_time;
public:
    Puck_Class(double mass_input, double radius_input, double update_time_input, vector<double> position_input, double friction_input);

    void change_momentum_line(Line_Class* line);

    void change_momentum_circle(Circle_Class* circle);
    void propose_new_position( double update_time);

};


#endif //SIMULATION_PUCK_CLASS_H
