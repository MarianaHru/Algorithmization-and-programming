cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)

# # Додаємо тести для lab11_1_1
# add_executable(lab11_1_1_unit_test lab11_1_1/lab11_1_1_unit_test.c lab11_1_1/lab11_1_1.c)
# target_compile_definitions(lab11_1_1_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab11_1_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# # Додаємо тести для lab11_1_2
# add_executable(lab11_1_2_unit_test lab11_1_2/lab11_1_2_unit_test.cpp lab11_1_2/lab11_1_2.cpp)
# target_compile_definitions(lab11_1_2_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab11_1_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# # Додаємо тести для lab11_2
# add_executable(lab11_2_unit_test lab11_2/lab11_2_unit_test.cpp lab11_2/lab11_2.cpp)
# target_compile_definitions(lab11_2_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab11_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# Додаємо тести для lab11_3
add_executable(lab11_3_unit_test lab11_3/lab11_3_unit_test.cpp lab11_3/lab11_3.cpp)
target_compile_definitions(lab11_3_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab11_3_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)
