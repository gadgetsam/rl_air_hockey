//
// Created by gadge on 3/7/2019.
//

#ifndef SIMULATION_LINE_CLASS_H
#define SIMULATION_LINE_CLASS_H

#include <vector>
#include <iterator>
#include <array>
using namespace std;
class Line_Class {
protected:
    vector<double> start;
    vector<double> end;
    int line_direction;
public:
    Line_Class(vector<double> start_input, vector<double> end_input, int line_direction_input){
        start = start_input;
        end = end_input;
        line_direction = line_direction_input;
    };
};


#endif //SIMULATION_LINE_CLASS_H
