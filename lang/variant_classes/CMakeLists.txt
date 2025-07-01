cmake_minimum_required(VERSION 3.10)

project(variant_classes)

add_executable(
    ${PROJECT_NAME}
    circle.hpp
    coord.hpp
    line.hpp
    rectangle.hpp
    main.cpp
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

