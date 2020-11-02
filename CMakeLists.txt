cmake_minimum_required(VERSION 3.15)
project(codes_learn_cpp)
set(CMAKE_CXX_STANDARD 17)

FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/**/*.cpp")

# 指定头文件目录
#INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

#===================== 生成.so库配置 start ======================================
# 指定输出 .so 动态库的目录位置
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


# 指定生成动态库
#ADD_LIBRARY(codes_learn_cpp SHARED ${SRC_LIST})

# 指定生成版本号，VERSION指代动态库版本，SOVERSION指代API版本
#SET_TARGET_PROPERTIES(codes_learn_cpp PROPERTIES VERSION 1.2 SOVERSION 1)

#====================== 生成.so库配置 end =============================================

#======================= run application start ==============================================
add_executable(codes_learn_cpp main.cpp ${SRC_LIST})
#============================= run application end============================================
