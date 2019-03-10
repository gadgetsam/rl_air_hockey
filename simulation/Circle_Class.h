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
    vector<double> max_position;
    double radius;
    double mass;
    double update_time;

public:
    vector<double> get_velocity(){return velocity;};
    vector<double> get_position(){return position;};
    vector<double> get_position_proposed(){ return position_proposed;};
    double get_radius(){ return radius;};
    double get_mass(){ return mass;};
    double get_update_time(){return update_time;};
    Circle_Class(double mass_input, double radius_input, double update_time_input, vector<double> position_input,
            vector<double> max_position_input);
    Circle_Class();
    bool line_collision(Line_Class* line);
    bool circle_collision(Circle_Class* circle);
    vector<double> check_position_inbounds();

};


#endif //SIMULATION_CIRCLE_CLASS_H
