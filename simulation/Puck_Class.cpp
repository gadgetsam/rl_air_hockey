//
// Created by gadge on 3/7/2019.
//

#include "Puck_Class.h"
#include "helpful_functions.cpp"
//TODO implement puck class
Puck_Class::Puck_Class(double mass_input, double radius_input, double update_time_input, vector<double> position_input,
                       double friction_input) {};
Puck_Class::Puck_Class() :Circle_Class(){};
//TODO implement change_momentum_circle for puck_class
void Puck_Class::change_momentum_circle(Circle_Class *circle) {}
//TODO implement change_momentum_line for puck_class
void Puck_Class::change_momentum_line(Line_Class *line) {}

void Puck_Class::propose_new_position(double update_time) {
    position_proposed.clear();
    position_proposed = add(scalar_multiply(velocity, update_time), position);
    position_proposed = check_position_inbounds();
}
