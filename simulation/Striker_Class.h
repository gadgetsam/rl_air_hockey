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
    Striker_Class(double mass_input, double radius_input, double update_time_input,
            vector<double> position_input, vector<double> max_position_input, int striker_ID_input) : Circle_Class(mass_input, radius_input,
                    update_time_input,position_input, max_position_input) {
        striker_ID=striker_ID_input;
    }
    Striker_Class() : Circle_Class(){
        striker_ID = 0;
    }
    void propose_new_position(double update_time, vector<double> velocity_input){
        position_proposed.clear();
        position_proposed = add(scalar_multiply(velocity_input, update_time), position);
        position_proposed = check_position_inbounds(striker_ID);

    }

};


#endif //SIMULATION_STRIKER_CLASS_H
