cmake_minimum_required(VERSION 3.10)

project(tracker)

add_executable(
    ${PROJECT_NAME}
    tracker.hpp
    main.cpp
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

