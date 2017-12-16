cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(acme)

set(SUBPROJECTS
    ${PROJECT_NAME}-array
    ${PROJECT_NAME}-test
    ${PROJECT_NAME}-eh128148
    )

macro(find_package)
    if(NOT "${ARGV0}" IN_LIST SUBPROJECTS)
        _find_package(${ARGV})
    endif()
endmacro()

foreach(subproj IN LISTS SUBPROJECTS)
    add_subdirectory(${subproj})
endforeach()
