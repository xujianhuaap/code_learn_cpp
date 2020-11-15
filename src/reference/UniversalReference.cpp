//
// Created by xujianhua on 2020/11/14.
//

#include <iostream>
#include <vector>

//要实现移动语义（MoveSemantic)必须实现移动构造函数和移动赋值操作符号函数（overload)
//std::move()将一个左值转换成一个右值引用
// 临时表达式的结果是右值例如： std::cout << 7+9 << std::endl
//右值引用有效的延长了右值的生命周期

//根据参数引用类型进行方法overload
//调用的时候可以是non-const_left_value，non-const_left_value_reference, non-const_right_value_reference
void runCode(std::string &value){
    std::cout << "run code string&" << std::endl;
}

void runCode(const std::string &value){
    std::cout << "run code const string&" << std::endl;
}
// 调用的时候可以是right_value("4"); non_const_right_value_ref（getNonConstantValue())
// runCode(getConstantValue()) 是非法的，getConstantValue()返回的是const_right_value_ref
void runCode(std::string &&value){
    std::cout << "run code string&&" << std::endl;
}

void runCode(const std::string &&value){
    std::cout << "run code const string&&" << std::endl;
}

const std::string getConstantValue(){
    return "1";
}
std::string getNonConstantValue(){
    return "1";
}





