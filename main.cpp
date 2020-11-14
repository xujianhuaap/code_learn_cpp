#include <iostream>
#include "src/object/Object.h"
#include "src/object/Static.h"
#include "src/reference/UniversalReference.cpp"

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
    int value{3};
    int& value_ref{value};
    int&& _right_value_ref{3};

    universalReference(3);
    universalReference(value);
    universalReference(value_ref);
    universalReference(_right_value_ref);

    std::vector<int>container;
    container.push_back(3);
    rightValueReference1(std::move(container));
}
//=====================　reference (right)end ====================================
int main() {
    main_right_value_reference();

    return 0;
}




