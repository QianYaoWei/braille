CMAKE_MINIMUM_REQUIRED(VERSION 2.8)                                                                                                                                                                                                     

# 编译选项
IF( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -pthread")
ELSE( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    SET(CMAKE_BUILD_TYPE "Release")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -pthread")
ENDIF( CMAKE_BUILD_TYPE STREQUAL "Debug" )


SET(INCLUDE_DIR_List
    ${CMAKE_CURRENT_SOURCE_DIR}/utility/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/utility/component/
)

SET(SRC_DIRS

    phone
    reader
    core
)

# 头文件搜索路径
INCLUDE_DIRECTORIES(${INCLUDE_DIR_List})

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
FOREACH (var ${SRC_DIRS})
    AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/${var} SRC_LIST)
ENDFOREACH (var)

ADD_EXECUTABLE(braille ${SRC_LIST})

