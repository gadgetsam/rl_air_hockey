//
// Created by gadge on 3/7/2019.
//

#ifndef SIMULATION_PASSING_STRUCTURES_H
#define SIMULATION_PASSING_STRUCTURES_H

struct Position_And_Velocity{
    vector<double> position;
    vector<double> velocity;
};
struct Update_Return{
    int goal;
    vector<double> puck_position;
    vector<double> striker_1_position;
    vector<double> striker_2_position;
};
#endif //SIMULATION_PASSING_STRUCTURES_H

