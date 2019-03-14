//
// Created by gadge on 3/7/2019.
//

#include "Circle_Class.h"
#include <math.h>

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
Line_Collision_Return Circle_Class::line_collision(Line_Class *line) {
    vector<double> line_start = line->get_start();
    vector<double> line_end = line->get_end();
    double len = pythagorian(line_start, line_end);
    double projection = dot(subtract(position_proposed, line_start),
                                                     subtract(line_end, line_start))/pow(len,2);
    vector<double> closest_point = add(line_start, scalar_multiply(subtract(line_end,line_start), projection));

    double distance = pythagorian(closest_point, position_proposed);
    //    Line_Collision_Return temp;
    if(distance >= radius){
        vector<double> test = {0,0};

//        temp.collision = false;
//        temp.closest_point = test;
        return {false, test};
    }
//    temp.collision= true;
//    temp.closest_point = closest_point;
    return {true, closest_point};
}
//side should be -1 if it is used for puck;
vector<double> Circle_Class::check_position_inbounds( int side) {
    vector<double> temp = position_proposed;

        if(position_proposed[0] > max_position[0]-radius){
            temp[0] = max_position[0]-radius;
        }
        if(position_proposed[0] < radius){
            temp[0] = radius;
        }
        if(position_proposed[1] > max_position[1]*((side ==0) ? .5 : 1)-radius){
            temp[1] = max_position[1]-radius;
        }
        if(position_proposed[1] < radius+max_position[1]*((side ==1) ? .5 : 0)){
            temp[1] = radius+ max_position[1]* ((side ==1) ? .5 : 0);
        }

    return temp;
}
void Circle_Class::reset(vector<double> start_position) {
velocity = {0,0};
position = start_position;
}
vector<double> Circle_Class::element_wise_multiplication(vector<double> v1, vector<double> v2){
    vector<double> temp;
    for(int x=0; x!=v1.size(); ++x){
        temp.push_back(v1[x]*v2[x]);
    }
    return temp;
}
double Circle_Class::sum(vector<double> v1){
    double total = 0;
    for(int x=0; x!=v1.size(); ++x){
        total += v1[x];
    }
    return total;
}
double Circle_Class::dot(vector<double> v1, vector<double> v2){
    return sum(element_wise_multiplication(v1, v2));
}

vector<double> Circle_Class::scalar_multiply(vector<double> v1, double scalar){
    vector<double> temp;
    for(int x=0; x!=v1.size(); ++x){
        temp.push_back(v1[x]*scalar);
    }
    return temp;
}
vector<double> Circle_Class::add(vector<double> v1, vector<double> v2){
    vector<double> temp;
    for(int x=0; x!=v1.size(); ++x){
        temp.push_back(v1[x]+v2[x]);
    }
    return temp;
}
vector<double> Circle_Class::subtract(vector<double> v1, vector<double> v2){
    vector<double> temp;
    for(int x=0; x!=v1.size(); ++x){
        temp.push_back(v1[x]+v2[x]);
    }
    return temp;
}
double Circle_Class::pythagorian(vector<double> v1, vector<double> v2){
    vector<double> temp = subtract(v1, v2);
    temp = element_wise_multiplication(temp, temp);
    double total = 0;
    for(int x=0; x!=v1.size(); ++x){
        total += temp[x];
    }
    return sqrt(total);
}