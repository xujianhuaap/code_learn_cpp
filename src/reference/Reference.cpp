//
// Created by xu on 2020/11/3.
//

#include <iostream>

//valueRef 可以看成是value的别名
//l-value vs r-value ;l-value 是包含内存地址的变量，赋值符号左边必须是l-value; 不是l-value就是r-value;
//引用必须被初始化，引用不能二次赋值（但可以对该引用下存储的值改变）
//引用经常用作方法的参数
//引用比指针更安全，尽量使用引用代替指针
//如果l-value 是non-const reference  ,那么r-value必须是non-const
void printNonConstantReferenceInfo() {
//    const int value {7};
    int value{7};
    int &valueRef{value};
    std::cout << "init value 7 , value\t" << value << "\t valueRef\t" << valueRef << std::endl;
    value = 8;
    std::cout << "change value 8, value\t" << value << "\t valueRef\t" << valueRef << std::endl;
    valueRef = 10;
    std::cout << "change valueRef 10, value\t" << value << "\t valueRef\t" << valueRef << std::endl;
    value = value +7;//赋值符号左边的变量value是l-value;赋值符号右边的value是r-value,先取出值再进行表达式运算
}

// 如果为 int arr[]作为方法的参数会退化成为int *arr，但是int(&arr)[] 引用不会
void printArrayReferenceInfo(int (&arr)[4]){

}

void printConstantReferenceInfo() {
    int value {7};
    const int &valueRef{value};
    std::cout << "init value 7 , value\t" << value << "\t valueRef\t" << valueRef << std::endl;
    value = 8;
    std::cout << "change value 8, value\t" << value << "\t valueRef\t" << valueRef << std::endl;
    value = value +7;//赋值符号左边的变量value是l-value;赋值符号右边的value是r-value,先取出值再进行表达式运算
}