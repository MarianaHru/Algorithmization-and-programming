# cmake_minimum_required(VERSION 3.10)
# project(MyProject)

# set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/scripts/buildsystems/vcpkg.cmake)

# include_directories(${GTEST_INCLUDE_DIRS})
# set(GTest_DIR /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/installed/x64-osx/share/gtest)
# find_package(GTest CONFIG REQUIRED)

# add_executable(lab5_1_unit_test lab5_1/lab5_1_unit_test.cpp lab5_1/lab5_1.cpp)
# target_compile_definitions(lab5_1_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab5_1_unit_test PRIVATE ${GTEST_LIBRARIES} pthread)

# add_executable(lab5_2_unit_test lab5_2/lab5_2_unit_test.cpp lab5_2/lab5_2.cpp)
# target_compile_definitions(lab5_2_unit_test PRIVATE UNIT_TESTING)
# target_link_libraries(lab5_2_unit_test PRIVATE ${GTEST_LIBRARIES} pthread)

cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)

# Додаємо тести для lab5_1
add_executable(lab5_1_unit_test lab5_1/lab5_1_unit_test.cpp lab5_1/lab5_1.cpp)
target_compile_definitions(lab5_1_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab5_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо тести для lab5_2
add_executable(lab5_2_unit_test lab5_2/lab5_2_unit_test.cpp lab5_2/lab5_2.cpp)
target_compile_definitions(lab5_2_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab5_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)

# Додаємо тести для lab5_3
add_executable(lab5_3_unit_test lab5_3/lab5_3_unit_test.cpp lab5_3/lab5_3.cpp)
target_compile_definitions(lab5_3_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab5_3_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)
