#include <vector>
#include <string>
#include "array.h"

//
// Created by xu on 2020/11/4.
//
void printArrayInfo(){
    std::string name{"xu"};
    std::vector<std::string> vector;
    vector.push_back(std::move(name));

}

class PointerInfo{
public:
    PointerInfo(std::string name){
        this->name = name.c_str();
    }
    PointerInfo(){
      this->name ="default";
    }
    const char* name;

};
void newArrayCase(){
    //作为一个数组首个元素的地址
    PointerInfo* info = new PointerInfo[3]();
    printf("%s",info[1].name);
}
