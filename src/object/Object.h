//
// Created by xujianhua on 2020/11/4.
//

#ifndef CODES_LEARN_CPP_OBJECT_H
#define CODES_LEARN_CPP_OBJECT_H
#include <string>
#include <iostream>
#include "Person.h"
#include "Teacher.h"
// struct 目前支持拥有成员方法，但不支持这样做，完全可以使用class 代替
// struct 成员默认访问修饰符是public class 成员默认访问修饰符号是private
// struct 以public方式继承父类，class 默认以private的方式继承父类
//class A拥有私有成员变量m_xx,成员函数F,F的参数parameter是A类型，则该成员方法内parameter.m_xx是可以调用的;F的参数parameter不是该类型则不可以

class Teacher;
class Person;
struct Student:Person{
};
#endif //CODES_LEARN_CPP_OBJECT_H
