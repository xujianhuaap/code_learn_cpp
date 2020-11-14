//
// Created by xu on 2020/11/9.
//

#ifndef CODES_LEARN_CPP_STATIC_H
#define CODES_LEARN_CPP_STATIC_H
//模板函数的声明与实现不能分割成h/.cpp文件
template <typename T> void print1(const T &value);

template <typename T> inline void print1(const T &value){
    std::cout << value << std::endl;
}

template <class T> class PrintTool{
    std::string m_name;
    T m_t;
public:
    PrintTool<T>(std::string name, T &t):m_name{name},m_t{t}{};
    void printInfo();
    static void print();
};

template <class T> inline void PrintTool<T>::printInfo(){
    std::cout << m_name << std::endl;
}


template <typename T>  void PrintTool<T>::print(){
    print1(std::move("123"));
}
#endif //CODES_LEARN_CPP_STATIC_H
