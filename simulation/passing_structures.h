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
    int goal = 0;
    Position_And_Velocity puck;
    Position_And_Velocity striker_1;
    Position_And_Velocity striker_2;
};
#endif //SIMULATION_PASSING_STRUCTURES_H

