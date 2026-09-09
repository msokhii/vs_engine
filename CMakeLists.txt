cmake_minimum_required(VERSION 3.10)

project(vs_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(vs_engine
    src/main.cpp
    src/Vector.cpp
    src/Similarity.cpp
    src/vdb.cpp
    src/SearchEngine.cpp
)
