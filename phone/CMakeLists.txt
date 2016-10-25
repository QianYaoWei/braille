CMAKE_MINIMUM_REQUIRED(VERSION 2.8)                                                                                                                                                                                                   
SET (proDir              

     button
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
FOREACH (var ${proDir})  
    INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/${var})
ENDFOREACH (var)         

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
FOREACH (var ${proDir})  
    AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/${var} SRC_LIST)
ENDFOREACH (var)         

# LINK_DIRECTORIES(${LIB_DIR_LIST})
ADD_LIBRARY(phone STATIC ${SRC_LIST})
