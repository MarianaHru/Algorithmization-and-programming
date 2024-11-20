cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)

# # Додаємо тести для lab10_1_A
# add_executable(lab10_1_A_unit_test lab10_1_A/lab10_1_A_unit_test.cpp lab10_1_A/lab10_1_A.cpp)
# target_compile_definitions(lab10_1_A_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab10_1_A_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# # Додаємо тести для lab10_1_B
# add_executable(lab10_1_B_unit_test lab10_1_B/lab10_1_B_unit_test.cpp lab10_1_B/lab10_1_B.cpp)
# target_compile_definitions(lab10_1_B_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab10_1_B_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# # Додаємо тести для lab10_2_A
# add_executable(lab10_2_A_unit_test lab10_2_A/lab10_2_A_unit_test.cpp lab10_2_A/lab10_2_A.cpp)
# target_compile_definitions(lab10_2_A_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab10_2_A_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab10_3
add_executable(lab10_3_unit_test lab10_3/lab10_3_unit_test.cpp lab10_3/lab10_3.cpp)
target_compile_definitions(lab10_3_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab10_3_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)