cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)


# Додаємо тести для lab7_1
add_executable(lab7_1_unit_test lab7_1/lab7_1_unit_test.cpp lab7_1/lab7_1.cpp)
target_compile_definitions(lab7_1_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab7_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab7_1_rec
add_executable(lab7_1_unit_test_rec lab7_1_rec/lab7_1_unit_test_rec.cpp lab7_1_rec/lab7_1_rec.cpp)
target_compile_definitions(lab7_1_unit_test_rec PRIVATE UNIT_TESTING)
target_link_libraries(lab7_1_unit_test_rec PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab7_2
add_executable(lab7_2_unit_test lab7_2/lab7_2_unit_test.cpp lab7_2/lab7_2.cpp)
target_compile_definitions(lab7_2_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab7_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# Додаємо тести для lab7_2_rec
add_executable(lab7_2_unit_test_rec lab7_2_rec/lab7_2_unit_test_rec.cpp lab7_2_rec/lab7_2_rec.cpp)
target_compile_definitions(lab7_2_unit_test_rec PRIVATE UNIT_TESTING)
target_link_libraries(lab7_2_unit_test_rec PRIVATE GTest::gtest GTest::gtest_main pthread)
