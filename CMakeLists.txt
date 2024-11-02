cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)

# Додаємо тести для lab8_1_it
add_executable(lab8_1_unit_test_it lab8_1_it/lab8_1_unit_test_it.cpp lab8_1_it/lab8_1.cpp)
target_compile_definitions(lab8_1_unit_test_it PRIVATE UNIT_TESTING)
target_link_libraries(lab8_1_unit_test_it PRIVATE GTest::gtest GTest::gtest_main pthread)


# # Додаємо тести для lab8_1_rec
# add_executable(lab8_1_unit_test_rec lab8_1_rec/lab8_1_unit_test_rec.cpp lab8_1_rec/lab8_1_rec.cpp)
# target_compile_definitions(lab8_1_unit_test_rec PRIVATE UNIT_TESING)
# target_link_libraries(lab8_1_unit_test_rec PRIVATE GTest::gtest GTest::gtest_main pthread)


add_executable(lab8_1_app lab8_1_rec/lab8_1_rec.cpp)
add_executable(lab8_1_unit_test_rec lab8_1_rec/lab8_1_rec.cpp lab8_1_rec/lab8_1_unit_test_rec.cpp)
target_link_libraries(lab8_1_unit_test_rec PRIVATE gtest gtest_main)  
target_compile_definitions(lab8_1_unit_test_rec PRIVATE UNIT_TESTING)
find_package(GTest REQUIRED)
target_link_libraries(lab8_1_unit_test_rec PRIVATE GTest::GTest GTest::Main)



# Додаємо тести для lab8_1_str
add_executable(lab8_1_unit_test_str lab8_1_str/lab8_1_unit_test_str.cpp lab8_1_str/lab8_1_str.cpp)
target_compile_definitions(lab8_1_unit_test_str PRIVATE UNIT_TESTING)
target_link_libraries(lab8_1_unit_test_str PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab8_1_char
add_executable(lab8_1_unit_test_char lab8_1_char/lab8_1_unit_test_char.cpp lab8_1_char/lab8_1_char.cpp)
target_compile_definitions(lab8_1_unit_test_char PRIVATE UNIT_TESTING)
target_link_libraries(lab8_1_unit_test_char PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab8_2
add_executable(lab8_2_unit_test lab8_2/lab8_2_unit_test.cpp lab8_2/lab8_2.cpp)
target_compile_definitions(lab8_2_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab8_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)