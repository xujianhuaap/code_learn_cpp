#include <vector>
#include <string>

//
// Created by xu on 2020/11/4.
//
void printArrayInfo(){
    std::string name{"xu"};
    std::vector<std::string> vector;
    vector.push_back(std::move(name));
}
