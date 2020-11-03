//
// Created by xu on 2020/11/3.
//

#include <iostream>

//valueRef 可以看成是value的别名
//
void printReferenceInfo() {
    int value {7};
    int &valueRef{value};
    std::cout << "init value 7 , value\t" << value << "\t valueRef\t" << valueRef << std::endl;
    value = 8;
    std::cout << "change value 8, value\t" << value << "\t valueRef\t" << valueRef << std::endl;
    valueRef = 10;
    std::cout << "change valueRef 10, value\t" << value << "\t valueRef\t" << valueRef << std::endl;
}