#include <iostream>
#include "src/object/Object.h"
//=====================　Linkage start ====================================
//一个方法可以有多个声明的地方; 此处声明　可以链接到ExternalLinkage.cpp文件中对应的方法
//ps: CMakeLists.txt 文件中必须通过add_executable(...)将ExternalLinkage.cpp 加入到编译文件的集合中
void sayHi();//pre-declare function
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
//=====================　pointer end ====================================

//=====================　reference start  ====================================
void printNonConstantReferenceInfo();
void printConstantReferenceInfo();
void main_reference();
void main_reference() {
    printNonConstantReferenceInfo();
    printConstantReferenceInfo();
}
//=====================　reference end ====================================

//=====================　object start ====================================

//=====================　object end ====================================

int main() {
    Student student{(std::string) "Student"};
    student.printInfo();
    const Teacher teacher{(std::string) "A"};
    teacher.printTeacherInfo();
    return 0;
}

