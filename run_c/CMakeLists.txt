cmake_minimum_required(VERSION 3.10)

project(runclib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_link_options(-L./ -lpetracalltest)

add_executable(runclib
    main.cpp
)

target_include_directories(runclib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.
)

target_link_directories(runclib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/.
)

target_link_libraries(runclib
    -lpetracalltest
)
