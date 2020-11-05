//
// Created by xujianhua on 2020/11/5.
//
#include <iostream>
#include "Person.h"

//class 如果仅在一个文件使用，只需要在使用的文件定义；
// 如果需要在多个文件使用，那么可以将class声明在一个header文件内，header文件定义成员变量，构造器方法，析构器方法，访问成员变量方法，以及
//声明其他方法。在class_xx.cpp文件内实现在header文件内声明的方法
void Person::printInfo(){
    std::cout << m_name << std::endl;
}

void Person::copyFrom(const Person &student){
    m_name = student.m_name;
}