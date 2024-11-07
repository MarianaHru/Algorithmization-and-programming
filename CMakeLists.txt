cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)


# Додаємо тести для lab9_1
add_executable(lab9_1_unit_test lab9_1/lab9_1_unit_test.cpp lab9_1/lab9_1.cpp)
target_compile_definitions(lab9_1_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab9_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)
