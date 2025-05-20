cmake_minimum_required(VERSION 3.10)

project(pmr_track_new)

add_executable(
    ${PROJECT_NAME}
    tracknew.hpp
    main.cpp
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)


add_executable(
    tracknew
    tracknew.hpp
    tracknew.cpp
)

set_target_properties(
    tracknew
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

