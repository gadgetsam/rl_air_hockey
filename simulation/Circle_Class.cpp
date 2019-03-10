//
// Created by gadge on 3/7/2019.
//

#include "Circle_Class.h"
#include <math.h>
#include "helpful_functions.cpp"
Circle_Class::Circle_Class(double mass_input, double radius_input, double update_time_input,
                           vector<double> position_input,vector<double> max_position_input) {
    mass= mass_input;
    radius = radius_input;
    update_time = update_time_input;
    position = position_input;
    max_position = max_position_input;

}
Circle_Class::Circle_Class(){
    velocity = {0,0};
    position_proposed = {0,0};
    position = {0,0};
    max_position = {0,0};
    radius = 0;
    mass = 0;
    update_time= 0;

}

bool Circle_Class::circle_collision(Circle_Class* circle) {
    vector<double> circle_2_position = circle->get_position_proposed();
    double distance = pythagorian(position_proposed, circle_2_position);
    if(distance >= circle->get_radius()+radius){
        return true;
    }
    return false;

}
//TODO change to also return closest point
bool Circle_Class::line_collision(Line_Class *line) {
    vector<double> line_start = line->get_start();
    vector<double> line_end = line->get_end();
    double len = pythagorian(line_start, line_end);
    double projection = dot(subtract(position_proposed, line_start),
                                                     subtract(line_end, line_start))/pow(len,2);
    vector<double> closest_point = add(line_start, scalar_multiply(subtract(line_end,line_start), projection));
    double distance = pythagorian(closest_point, position_proposed);
    if(distance >= radius){
        return false;
    }
    return true;
}

vector<double> Circle_Class::check_position_inbounds() {
    vector<double> temp = position_proposed;
    if(position_proposed[0] > max_position[0]-radius){
        temp[0] = max_position[0]-radius;
    }
    if(position_proposed[0] < radius){
        temp[0] = radius;
    }
    if(position_proposed[1] > max_position[1]-radius){
        temp[1] = max_position[1]-radius;
    }
    if(position_proposed[1] < radius){
        temp[1] = radius;
    }
    return temp;
}