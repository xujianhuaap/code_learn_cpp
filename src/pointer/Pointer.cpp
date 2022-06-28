//
// Created by xu on 2020/11/3.
//

#include <iostream>
#include "Pointer.h"

int *iptr{};//declare a pointer,point to int value; * near the name
int* getAddress(); // function 返回一个指针, point to int value; * near the type

//double *dPtr{ 0x0012FF7C }; // not okay　C++ 不允许直接字符内存地址赋值给指针

//空指针
double *dPtr{0};//0表示指针的地址不存在

//&dPtr 若ptr是空指针，则&dPtr会闪退，为解决这一问题引入了宏NULL

void printPointerInfo(double *dPtr){
    std::cout << dPtr << std::endl;
    if(dPtr)
        //非空指针
        std::cout << *dPtr << std::endl;
    else
        //空指针
        std::cout << "null pointer"  << std::endl;
}

//这里double array[] 会被转化成　double *array　这种现象称为数组退化
//指针运算 指针＋１　表示指针目前的内存地址指向下一个元素所在的网络地址
//对于non-char pointer,std::cout 直接打印指针地址；对于const char pointer 或者　char pointer std::cout 打印成string
void printArrayInfo(double array[]){
    std::cout << "address is \t"<<array << "\t array[0] is\t" << *array << std::endl;
    std::cout << "not array length, but address size " << sizeof(array) << "\t byte"<< std::endl;
    std::cout << "array[1] value " << *(array+1) << std::endl;
}

// 当new操作失败的时候（操作系统无法分配内存）std::nothrow 保证返回一个空指针的地址而不是一个随机地址
// 在删除　动态指针后如果 在该区域块内还有其他操作务必将指针指向空指针
// 一块动态内存区域尽量只有一个指针。如果不能保证尽量分清职责，分配该区域的指针负责delete,其他指针只是访问
//已经返回给系内存的指针称为悬浮指针，不能用于再次delete 或者 解引用操作（*ptr);
//内存泄露
void printDynamicalPointer(){
    int *iPtr = new(std::nothrow)int(5);
    delete iptr;
    iptr = nullptr;
    //TODO other operation
}

