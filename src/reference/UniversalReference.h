//
// Created by xujianhua on 2020/11/15.
//

#ifndef CODES_LEARN_CPP_UNIVERSALREFERENCE_H
#define CODES_LEARN_CPP_UNIVERSALREFERENCE_H

#include <string>
#include <vector>

//右值引用分为(named right value reference) 和 (unnamed right value reference) 见于模板函数

//此处为指明non-const右值引用,可以绑定 non-const_right_value_ref; right_value
void myForward(std::string &&t);
void myPerfectForward(std::string &&t);

void runCode(std::string &value);
void runCode(const std::string &value);
void runCode(std::string &&value);
void runCode(const std::string &&value);

//返回一个const-right_value_ref
const std::string getConstantValue();
//返回一个non-const_right_value
std::string getNonConstantValue();

template <typename T>
void senorForward(T&& t);

template <typename T>
void rightValueReference1(std::vector<T> && rightValueRef);

//通过std::forward 可以帮组实现完美转化
//这里的右值引用是指明的右值引用（named right value reference);
// 只能使用right_value;non-const_right_value_reference初始化
void myForward(std::string &&t){
    // 这里并不能保持参数类型一致，因此并不能称为完美转发（perfect_forward)
    // 右值引用也是左值类型
    runCode(t);
}

void myPerfectForward(std::string &&t){
    runCode(std::forward<std::string>(t));
}



//引用折叠 所有的右值叠加到一个右值引用，是右值（左值类型）；其他引用叠加是左值引用
//这里的T&& 是未指明的右值引用（它的类型T是推断而来）；初始化的时候可以是左值也可以是右值
template <typename T>
void senorForward(T&& t){
//    if(std::is_same<std::string, T>::value){
//        std::cout << "senorForward string" << std::endl;
//    } else if(std::is_same<std::string&, T>::value){
//        std::cout << "senorForward string&" << std::endl;
//    } else if (std::is_same<std::string&&, T>::value){
//        std::cout << "senorForward string&&" << std::endl;
//    } else{
//        std::cout << "senorForward other type" << std::endl;
//    }
    runCode(std::forward<T>(t));
}

//此处为右值引用，已经确定是vector了
template <typename T>
void rightValueReference1(std::vector<T> && rightValueRef){
    std::cout << rightValueRef.size() << std::endl;
}

#endif //CODES_LEARN_CPP_UNIVERSALREFERENCE_H
