//
// Created by xujianhua on 2020/11/5.
//

#ifndef CODES_LEARN_CPP_PERSON_H
#define CODES_LEARN_CPP_PERSON_H

//class 定义成员变量的时候建议赋默认值
//如果class 是一个构造器通过构造器成员变量初始化器初始化成员变量，而不是在构造器区块内（建议）
//对于拥有多个构造器的class,A构造器的方法实现，B构造器方法也有实现；可以有两种方式1》构造器代理 2》封装重叠代码成方法，所有构造器调用这个方法
//析构器不是必须的，只有class含有动态分配的内存的成员变量，file类型的成员变量，数据库引用的类型成员变量，才需要析构器做清除处理
class Person{
protected:
    int age{18};
    std::string m_name{"default"};
public:
    Person(std::string name):m_name{name}{}
    ~Person(){}
    void printInfo();

    //class A拥有私有成员变量m_xx,成员函数F,F的参数parameter是A类型，
    // 则该成员方法内parameter.m_xx是可以调用的;F的参数parameter不是该类型则不可以
    void copyFrom(const Person &student);
};
#endif //CODES_LEARN_CPP_PERSON_H
