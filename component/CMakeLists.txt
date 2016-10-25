CMAKE_MINIMUM_REQUIRED(VERSION 2.8)                                                                                                                                                                                                   
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
ADD_LIBRARY(component STATIC ${SRC_LIST})

