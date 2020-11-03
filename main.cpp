#include <iostream>

//一个方法可以有多个声明的地方; 此处声明　可以链接到ExternalLinkage.cpp文件中对应的方法
//ps: CMakeLists.txt 文件中必须通过add_executable(...)将ExternalLinkage.cpp 加入到编译文件的集合中
void sayHi();//pre-declare function
extern const double Pai;//pre-declare constant
extern std::string applicationName;//pre-declare non-constant

int main() {
    std::cout << "========\t" <<applicationName << "\t============" << std::endl;
    std::cout << "Pain value 【" << Pai << "】"<< std::endl;
    sayHi();
    return 0;
}
