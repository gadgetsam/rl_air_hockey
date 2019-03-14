//
// Created by gadge on 3/7/2019.
//

#include "Board_Class.h"
#include "Goal_Class.h"
#include "Line_Class.h"

#include "Wall_Class.h"
#include "passing_structures.h"
#include "Circle_Class.h"
Board_Class::Board_Class(double update_time_input , double puck_mass, double friction, double striker_mass, double striker_radius, double puck_radius) {
    //Goal positions
    vector<double> start_point_goal_0 = {0,0}; //Goal ID = 0
    vector<double> end_point_goal_0 = {0,0};  //Goal ID = 0
    vector<double> start_point_goal_1 = {0,0}; //Goal ID = 1
    vector<double> end_point_goal_1 = {0,0};  //Goal ID = 1
    //Wall Positions Walls 0 and 1 are horizontal, Walls 2, 3 are vertical
    vector<double> start_point_wall_0 = {0,0};
    vector<double> end_point_wall_0 = {0,0};
    vector<double> start_point_wall_1 = {0,0};
    vector<double> end_point_wall_1 = {0,0};
    vector<double> start_point_wall_2 = {0,0};
    vector<double> end_point_wall_2 = {0,0};
    vector<double> start_point_wall_3 = {0,0};
    vector<double> end_point_wall_3 = {0,0};
    //Max position for puck and strikers, note for strikers it is split in the update code into two separate sides
    vector<double> max_position = {0,0};
    //Puck Starting Position
    vector<double> start_position_puck = {0,0};
    start_positions.push_back(start_position_puck);
    //Striker start positions, striker 0 starts on side close y=0 and striker 1 starts on side close to y=48
    vector<double> start_position_striker_0 = {0,0};
    start_positions.push_back(start_position_striker_0);
    vector<double> start_position_striker_1 = {0,0};
    start_positions.push_back(start_position_striker_1);


    //Create objects and add to appropriate lists
    vector<Goal_Class> goals = {Goal_Class(start_point_goal_0, end_point_goal_0, 0), Goal_Class(start_point_goal_0, end_point_goal_0, 1)};
    puck = Puck_Class(puck_mass, puck_radius, update_time_input, start_position_puck, max_position, friction);
    vector<Wall_Class> walls = {Wall_Class(start_point_wall_0, end_point_wall_0, 0), Wall_Class(start_point_wall_1, end_point_wall_1, 1), Wall_Class(start_point_wall_2, end_point_wall_2, 2), Wall_Class(start_point_wall_3, end_point_wall_3, 3)};
    vector<Striker_Class> strikers = {Striker_Class(striker_mass, striker_radius, update_time_input, start_position_striker_0, max_position, 0), Striker_Class(striker_mass, striker_radius, update_time_input, start_position_striker_1, max_position, 1)};
}

void Board_Class::reset() {
    puck.reset(start_positions[0]);
    strikers[0].reset(start_positions[1]);
    strikers[1].reset(start_positions[2]);
}
//TODO implement board class update
Update_Return Board_Class::update(double striker_1_x_velocity, double striker_1_y_velocity, double striker_2_x_velocity,
                                  double striker_2_y_velocity, double update_time) {
    //    apply velocities to all objects creating a proposed next place for all of them
    strikers[0].propose_new_position(update_time, {striker_1_x_velocity, striker_1_y_velocity});
    strikers[1].propose_new_position(update_time, {striker_2_x_velocity, striker_2_y_velocity});
    puck.propose_new_position(update_time);

    //    Check if puck is touching a mallet by using center distance then calculate change in momentum then update proposed positions
    if(puck.circle_collision(&(strikers[0]))){
        puck.change_momentum_circle(&(strikers[0]));
    }
    if(puck.circle_collision(&(strikers[1]))){
        puck.change_momentum_circle(&(strikers[1]));
    }
    //    Check if puck is touching goal then immediately return score and call reset model
    Line_Collision_Return goal_0 = puck.line_collision(&(goals[0]);
    Line_Collision_Return goal_1 = puck.line_collision(&(goals[1]);
    if(goal_0.collision){
        reset();
        return {-1,puck.get_position_proposed(), strikers[0].get_position_proposed(), strikers[1].get_position_proposed()};
    }
    if(goal_1.collision){
        reset();
        return {-1,puck.get_position_proposed(), strikers[0].get_position_proposed(), strikers[1].get_position_proposed()};
    }
//    Check if puck is in collision with wall if it is change velocity accordingly then update proposed positions
    for(int i =0; i!=4; ++i){
        if(puck.line_collision(&(walls[i])).collision){
            puck.change_momentum_line(&(walls[i]));
        }
    }

//    Update current positions and velocities
//TODO add this in
//    Return current positions
    return {0,puck.get_position(), strikers[0].get_position(), strikers[1].get_position()};

}
