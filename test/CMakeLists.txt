add_executable(test_dice test_dice.cpp)

target_include_directories(test_dice
    PUBLIC
        "${PROJECT_SOURCE_DIR}/include/utility"

)

target_link_libraries(test_dice dice)
