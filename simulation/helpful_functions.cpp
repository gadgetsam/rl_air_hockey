//
// Created by gadge on 3/9/2019.
//
#include <math.h>
vector<double> element_wise_multiplication(vector<double> v1, vector<double> v2){
    vector<double> temp;
    for(int x=0; x!=v1.size(); ++x){
        temp.push_back(v1[x]*v2[x]);
    }
    return temp;
}
double sum(vector<double> v1){
    double total = 0;
    for(int x=0; x!=v1.size(); ++x){
        total += v1[x];
    }
    return total;
}
double dot(vector<double> v1, vector<double> v2){
    return sum(element_wise_multiplication(v1, v2));
}

vector<double> scalar_multiply(vector<double> v1, double scalar){
    vector<double> temp;
    for(int x=0; x!=v1.size(); ++x){
        temp.push_back(v1[x]*scalar);
    }
    return temp;
}
vector<double> add(vector<double> v1, vector<double> v2){
    vector<double> temp;
    for(int x=0; x!=v1.size(); ++x){
        temp.push_back(v1[x]+v2[x]);
    }
    return temp;
}
vector<double> subtract(vector<double> v1, vector<double> v2){
    vector<double> temp;
    for(int x=0; x!=v1.size(); ++x){
        temp.push_back(v1[x]+v2[x]);
    }
    return temp;
}
double pythagorian(vector<double> v1, vector<double> v2){
    vector<double> temp = subtract(v1, v2);
    temp = element_wise_multiplication(temp, temp);
    double total = 0;
    for(int x=0; x!=v1.size(); ++x){
        total += temp[x];
    }
    return sqrt(total);
}
