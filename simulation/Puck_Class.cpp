//
// Created by gadge on 3/7/2019.
//

#include "Puck_Class.h"
Puck_Class::Puck_Class(double mass_input, double radius_input, double update_time_input, vector<double> position_input, vector<double> max_position_input,
                       double friction_input) : Circle_Class(mass_input, radius_input, update_time_input, position_input, max_position_input){};
Puck_Class::Puck_Class() :Circle_Class(){};

void Puck_Class::change_momentum_circle(Circle_Class *circle) {
    double newVelX1 = (velocity[0]* (mass - (circle->get_mass())) + (2 * (circle->get_mass()) * circle->get_velocity()[0])) / (mass + (circle->get_mass()));
    double newVelY1 = (velocity[1] * (mass - (circle->get_mass())) + (2 * (circle->get_mass()) * circle->get_velocity()[1])) / (mass + (circle->get_mass()));
//    double newVelX2 = (circle->get_velocity()[0] * ((circle->get_mass()) - mass) + (2 * mass * velocity[0])) / (mass + (circle->get_mass()));
//    double newVelY2 = (circle->get_velocity()[1] * ((circle->get_mass()) - mass) + (2 * mass * velocity[1])) / (mass + (circle->get_mass()));
// only need to calculate velocity change for the puck, strikers don't change velocity.
    velocity[0] = newVelX1;
    velocity[1] = newVelY1;
    propose_new_position(update_time);
}

void Puck_Class::change_momentum_line(Line_Class *line) {
    if(line->get_line_direction()==0){
        velocity[1]= -1*velocity[1];
    }
    if(line->get_line_direction()==1){
        velocity[0]= -1*velocity[0];
    }
    propose_new_position(update_time);
}

void Puck_Class::propose_new_position(double update_time_input) {
    velocity[0] *= (1.0-friction);
    velocity[1] *= (1.0-friction);
    update_time = update_time_input;
    position_proposed.clear();
    position_proposed = add(scalar_multiply(velocity, update_time_input), position);
    position_proposed = check_position_inbounds();
}
