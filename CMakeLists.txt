cmake_minimum_required(VERSION 3.16)
project(isdn3000e_lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO: Import the external libraries you are using
set(Eigen3_DIR "/opt/homebrew/Cellar/eigen@3/3.4.1/share/eigen3/cmake")
include(FetchContent)

FetchContent_Declare(
  igl
  GIT_REPOSITORY https://github.com/libigl/libigl.git
  GIT_TAG        v2.5.0 # Use a specific release tag
)


FetchContent_Declare(
        polyscope
        GIT_REPOSITORY https://github.com/nmwsharp/polyscope.git
        GIT_TAG master)


FetchContent_MakeAvailable(polyscope)
FetchContent_MakeAvailable(igl)

add_executable(isdn3000e_lab3 main.cpp
        tasks/task1.h
        tasks/task1.cpp
        tasks/task2.cpp
        tasks/task2.h
        tasks/task3.cpp
        tasks/task3.h
        tasks/task4.cpp
        tasks/task4.h
        )
find_package(Eigen3 REQUIRED) 
target_link_libraries(isdn3000e_lab3 PUBLIC Eigen3::Eigen)
target_link_libraries(isdn3000e_lab3 PUBLIC polyscope)     
target_link_libraries(isdn3000e_lab3 PUBLIC igl::core)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/assets)
configure_file(
        ${CMAKE_SOURCE_DIR}/assets/bunny.obj
        ${CMAKE_BINARY_DIR}/assets/bunny.obj
        COPYONLY
)
