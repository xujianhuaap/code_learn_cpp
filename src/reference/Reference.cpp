//
// Created by xu on 2020/11/3.
//

#include <iostream>
// 表达式有两个属性 type 和 value(左值类型，右值类型）

//valueRef 可以看成是value的别名
//l-value vs r-value ;l-value 是包含内存地址的变量，赋值符号左边必须是l-value; 不是l-value就是r-value;
//引用必须被初始化，引用不能二次赋值（但可以对该引用下存储的值改变）
//引用经常用作方法的参数
//引用比指针更安全，尽量使用引用代替指针
//如果l-value 是non-const reference  ,那么r-value必须是non-const
void printNonConstantLeftValueReferenceInfo() {
    int value{7};//non-const left-value
    const int const_value{8};//const left-value

    int& value_ref{value};//non-const left_value_ref
    const int& const_value_ref{0};//const left_value_ref

    //右值引用本身是一个左值类型
    int&& right_value_ref{8};//non-const right_value_ref

    //non-const left_value_ref 可以使用non-const left_value;non-const left_value_ref;non-const right_value_ref初始化
    //但不能被right_value，const left_value,const left_value_ref ；const_right_value_ref;
    int &valueRef{value};
    int &valueRef2{value_ref};
    int &valueRef3{right_value_ref};
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

void printConstantLeftValueReferenceInfo() {
    int value {7};//non-const_left_value
    const int const_value{8};//const_left_value

    int &valueRef{value};//non_const_left_value_ref
    const int &const_valueRef{value};//const_left_value_ref

    const int &const_valueRef1{7};//const_left_value_ref
    const int &const_valueRef2{const_valueRef};//const_left_value_ref
    const int &const_valueRef3{valueRef};//const_left_value_ref
    const int &const_valueRef4{value};//const_left_value_ref
    const int &const_valueRef5{const_value};//const_left_value_ref

    std::cout << "init value 7 , value\t" << value << "\t valueRef\t" << valueRef << std::endl;
    value = 8;
    std::cout << "change value 8, value\t" << value << "\t valueRef\t" << valueRef << std::endl;
    value = value +7;//赋值符号左边的变量value是l-value;赋值符号右边的value是r-value,先取出值再进行表达式运算
}

//右值引用只能用右值初始化
//右值引用也是左值类型
//右值引用是对右值生命周期的延长
void printRValueReferenceInfo(){
    const int const_value{7};
    int var_value{8};
    int&& rValueRef{std::move(7)};
}