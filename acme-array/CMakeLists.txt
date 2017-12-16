cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(NAMESPACE acme)
set(COMPONENT array)
project(${NAMESPACE}-${COMPONENT})

add_library(${PROJECT_NAME} src/array.cpp)
add_library(${NAMESPACE}::${COMPONENT} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
