cmake_minimum_required(VERSION 3.16.3)

project(Tema_1)

if(CMAKE_VERSION GREATER "3.1.2") 
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()    
endif()

add_executable(Item4 Item4.cpp)
add_executable(Item5 Item5.cpp)  
add_executable(Item6 Item6.cpp)        
