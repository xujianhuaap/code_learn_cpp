#include <iostream>
#include "Linkage.h"

//
// Created by xujianhua on 2020/11/1.
//

//file-scope function is externalLinkage
 void sayHi(){
    std::cout << "hi" << std::endl;
}

// file-scope constant default is internalLinkage
//　change into externalLinkage by extern
extern const double Pai{3.1415};

//file-scope non-constant default is externalLinkage
std::string applicationName{"code_learn_cpp"};