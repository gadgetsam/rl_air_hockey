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
    Line_Class(){
        start.push_back(0);
        start.push_back(0);
        end.push_back(0);
        end.push_back(0);
        line_direction = 0;
    }
    vector<double> get_start(){return start;};
    vector<double> get_end(){return end;};
    int get_line_direction(){return line_direction;};
    //TODO add function to accept proposed position
};


#endif //SIMULATION_LINE_CLASS_H
