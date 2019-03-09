//
// Created by gadge on 3/7/2019.
//

#include "Board_Class.h"
//TODO implement board class initializer
Board_Class(double update_time, double puck_mass, double friction, double striker_mass){
    goals = [Goal_Class([2.9, 3.00],[2.9, 3.00], 0)];
//    puck = Puck_Class(puck_mass, friction);
//    walls = [Wall_Class(0), Wall_Class(1), Wall_Class(2), Wall_Class(3)];
}
//TODO implement board_class reset
void Board_Class::reset() {
}
//TODO implement board class update
Update_Return Board_Class::update(double striker_1_x_velocity, double striker_1_y_velocity, double striker_2_x_velocity,
                                  double striker_2_y_velocity) {

}
