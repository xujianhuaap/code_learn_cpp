//
// Created by xujianhua on 2020/11/14.
//

#include <iostream>
#include <vector>

// universal_reference 和 right_value_reference 看起来很像的

//要实现移动语义（MoveSemantic)必须实现移动构造函数和移动赋值操作符号函数（overload)
//std::move()将一个左值转换成一个右值
// 临时表达式的结果是右值例如： std::cout << 7+9 << std::endl
//



//引用折叠 所有的右值引用叠加到一个右值引用，是右值引用（左值类型）；其他引用叠加是左值引用
//这里的T&& 是通用引用（它的类型T是推断而来）
template <typename T>
void universalReference(T&& t){
    if(std::is_same<int, T>::value){
        std::cout << "int" << std::endl;
    } else if(std::is_same<int&, T>::value){
        std::cout << "int&" << std::endl;
    } else if (std::is_same<int&&, T>::value){
        std::cout << "int&&" << std::endl;
    }

}

//此处为右值引用，已经确定是vector了
template <typename T>
void rightValueReference1(std::vector<T> && rightValueRef){
    std::cout << rightValueRef.size() << std::endl;
}
