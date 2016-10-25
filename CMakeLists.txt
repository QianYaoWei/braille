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

    /usr/include/python2.7/
)

# 头文件搜索路径
INCLUDE_DIRECTORIES(${INCLUDE_DIR_List})

# 组件
SET(COMPONENTS

    component
    phone
    reader
)

# 添加MakeList子目录
FOREACH (var ${COMPONENTS})
    ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/${var})
ENDFOREACH (var)

# 当前目录源文件
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
ADD_EXECUTABLE(braille ${SRC_LIST})

# SET(LIB_DIR_LIST
# /home/wqy/s3m_server/avalon_new/lib/linux
# /home/wqy/server_new/lib/linux
# /home/wqy/s3m_server/third_party/LuaJIT-2.0.4/src
# /opt/app/mysql-5.6.23/lib
# /usr/local/mysql/lib
# /usr/lib64/mysql
# )

# 公共lib
SET(COMMONLIB
python2.7
)

TARGET_LINK_LIBRARIES(braille
${COMPONENTS}
${COMMONLIB}
)

#cmake  -DCMAKE_BUILD_TYPE=Debug ..
