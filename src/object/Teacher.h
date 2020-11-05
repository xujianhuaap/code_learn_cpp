//
// Created by xujianhua on 2020/11/5.
//

#ifndef CODES_LEARN_CPP_TEACHER_H
#define CODES_LEARN_CPP_TEACHER_H

#include "Person.h"

//class 继承类的时候默认是private形式,因此需要用public
class Teacher: public Person{
    std::string m_rank{"A"};
    std::string m_school{"春蕾小学"};
public:
    //在构造器初始化器，要么初始化成员变量，要么代理构造器，不可能二者同时存在
    //对于class具有多个构造器的话，如果多个构造器有重叠的代码，可以有两种方式消除重复代码
    // 1》使用构造代理器 ，缺点可能造成反复调用对方的循环，此外不能初始化成员变量
    // 2》将重复代码封装成方法f，每个构造器都调用该方法f。ps：f内存在动态分配内存时候，要小心处理；
    Teacher(std::string rank):Teacher{rank,"利民小学"}{};
    Teacher(std::string rank, std::string school):m_rank{rank},m_school{school},Person("Teacher"){};
    void printTeacherInfo();
};
#endif //CODES_LEARN_CPP_TEACHER_H
