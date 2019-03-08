//
// Created by gadge on 3/7/2019.
//

#ifndef SIMULATION_CIRCLE_CLASS_H
#define SIMULATION_CIRCLE_CLASS_H

#include "Line_Class.h"
#include "passing_structures.h"
class Circle_Class {
protected:
    vector<double> velocity;
    vector<double> position;
    vector<double> position_proposed;
    double radius;
    double mass;
    double update_time;
public:
    Circle_Class();
    bool line_collision(Line_Class* line);
    bool circle_collision(Circle_Class* circle);
    Position get_current_position();
};


#endif //SIMULATION_CIRCLE_CLASS_H
