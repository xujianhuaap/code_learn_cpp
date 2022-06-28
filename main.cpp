#include <iostream>
#include <cstring>
#include "src/object/Object.h"
#include "src/object/Static.h"
#include "src/reference/UniversalReference.h"
#include "src/strings/Strings.h"
#include "src/array/array.h"
#include "src/linkage/Linkage.h"
#include "src/pointer/Pointer.h"


//=====================　Linkage start ====================================
//一个方法可以有多个声明的地方; 此处声明　可以链接到ExternalLinkage.cpp文件中对应的方法
//ps: CMakeLists.txt 文件中必须通过add_executable(...)将ExternalLinkage.cpp 加入到编译文件的集合中

void main_linkage();

extern const double Pai;//pre-declare constant
extern std::string applicationName;//pre-declare non-constant

void main_linkage() {
    std::cout << "========\t" << applicationName << "\t============" << std::endl;
    std::cout << "Pain value 【" << Pai << "】"<< std::endl;
    sayHi();
}
//=====================　Linkage end====================================

//=====================　pointer start ====================================
double *nullPtrWithInt{0};//空指针
double *nullPtrWithMacro{NULL};//空指针以宏的形式定义
double *nullPtrAfterCpp11{nullptr};//空指针C++11之后才支持
extern void printPointerInfo(double *dPtr);
extern void printArrayInfo(double array[]);
void main_pointer();
void main_pointer() {
    printPointerInfo(nullPtrWithInt);
    printPointerInfo(nullPtrWithMacro);
    printPointerInfo(nullPtrAfterCpp11);
    double ages[]{1,2,3};
    printArrayInfo(ages);
}
void main_pointer_1();
void main_pointer_1(){
    PointerInfo * info = new PointerInfo("xu");
//    二级指针取值 只需要一个*就可以
    PointerInfo ** info_p = &info;
    std::cout << (int *)info_p << std::endl;
    std::cout << (* info_p)->m_name << std::endl;
    std::cout << (* info_p)->m_name << std::endl;
}
//=====================　pointer end ====================================

//=====================　reference start  ====================================
void printNonConstantLeftValueReferenceInfo();
void printConstantLeftValueReferenceInfo();
void main_reference();


void main_reference() {
    printNonConstantLeftValueReferenceInfo();
    printConstantLeftValueReferenceInfo();
}
//=====================　reference end ====================================

//=====================　object start ====================================
void main_class();



void main_class() {
    Student student{(std::string) "Student"};
    student.printInfo();
    const Teacher teacher{(std::string) "A"};
    teacher.printTeacherInfo();
    PrintTool<Student> tool ("Linux Printer",student);
    tool.printInfo();
    PrintTool<Student>::print();
    print1(std::move("1234"));

}
//=====================　object end ====================================

//=====================　 reference (right) start ====================================
void main_right_value_reference();
void main_right_value_reference() {
    std::string value{"3"};//左值 左值类型
    const std::string const_value{"3"};//常量左值 左值类型
    std::string& value_ref{value};// 左值引用 左值类型
    const std::string& const_value_ref{value};// 常量左值引用 左值类型
    std::string&& _right_value_ref{3};// 右值引用 左值类型
    const std::string&& const_right_value_ref{3};// 右值引用 左值类型

    const std::string&& value_ref1{getNonConstantValue()};

    myForward(std::string("3"));
    myForward(getNonConstantValue());
    myForward(std::move(value));

    myPerfectForward(std::string("3"));
    myPerfectForward(getNonConstantValue());
    myPerfectForward(std::move(value));
//    myForward(value_ref);
//    myForward(_right_value_ref);

    std::cout << "===========sensorForward===========" << std::endl;
    senorForward(std::string("3"));// 右值 + 未指明右值引用 -> 右值引用
    senorForward(value);                //左值+未指明右值引用->左值引用
    senorForward(value_ref);            //左值引用+未指明右值引用->左值引用
    senorForward(const_value_ref);      //常量左值引用+未指明右值引用->左值引用
    senorForward(_right_value_ref);     //右值引用+未指明右值引用->左值引用
    senorForward(const_value);          //常量左值+未指明右值引用-> 常量左值引用
    senorForward(getConstantValue());   //常量右值+未指明右值引用 ->常量右值引用
    senorForward(getNonConstantValue());   //右值+未指明右值引用 ->右值引用
}
//=====================　reference (right)end ====================================

//============= strings ===================
void main_strings();
void main_strings(){
   memsetCase();
}
//================ strings end =============

//======= array ======
void main_array();
void main_array(){
    newArrayCase();
}
//====== array end ====
int main() {
  main_pointer_1();

    return 0;
}




