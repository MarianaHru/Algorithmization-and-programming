cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)



# Додаємо тести для lab12_1
add_executable(lab12_1_unit_test lab12_1/lab12_1_unit_test.cpp lab12_1/lab12_1.cpp)
target_compile_definitions(lab12_1_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab12_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab12_4
add_executable(lab12_4_unit_test lab12_4/lab12_4_unit_test.cpp lab12_4/lab12_4.cpp)
target_compile_definitions(lab12_4_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab12_4_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)


