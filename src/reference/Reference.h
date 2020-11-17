//
// Created by xujianhua on 2020/11/17.
//

#ifndef CODES_LEARN_CPP_REFERENCE_H
#define CODES_LEARN_CPP_REFERENCE_H
// 默认的情况下C++,会提供默认的可以copy的构造器和可以copy赋值操作符号,
// 因此处理动态内存的class 要重写copy构造器和copy操作符号，以达到deep copy的目的

//移动语义采用 non-const right_value_reference 的风格，复制语义采用const left_value_reference
//因此只有赋值操作方法的参数是右值才会调用move语义的赋值操作符号的方法，只有构造器参数是右值的时候，才会调用move语义的构造器

//在移动语义的构造器中应该对构造器参数的指针型成员变量赋值nullptr,移动语义的赋值操作方法中应该对参数中的指针型成员变量赋值nullPtr;

#endif //CODES_LEARN_CPP_REFERENCE_H
