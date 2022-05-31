//
// Created by xu on 2022/5/31.
//

#ifndef CODES_LEARN_CPP_STRINGS_H
#define CODES_LEARN_CPP_STRINGS_H

//strcmp()比较
//memset()
class Strings {
private:

public:
    const char* name;
    int len = 10;
    Strings(std::string name){
        this->name = name.c_str();
    }
};

void memsetCase(){
    Strings* str = new Strings("i");
    memset(str,0,sizeof(*str));
    if(str -> name == nullptr && str->len == 0 ){
        std::printf("str is reset");
        return;
    }
    std::printf("%d\n", strcmp(str->name,"i") );
    if( !strcmp(str->name,"i")){//匹配的话
        std::printf("名称一样\n");
    }
}


#endif //CODES_LEARN_CPP_STRINGS_H
