add_library(dice OBJECT dice.cpp)

target_include_directories(dice
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include/utility"
)

add_library(utility dice.cpp)

target_include_directories(utility
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include/utility"
)
