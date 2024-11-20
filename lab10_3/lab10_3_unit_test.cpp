#include "lab10_3.h"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

TEST(AddResidentTest, AddsResidentSuccessfully)
{
    Resident residents[100];
    int count = 0;

    add_resident(residents, count, 1, true);

    ASSERT_EQ(count, 1);
    EXPECT_EQ(residents[0].room_number, 1);
    EXPECT_TRUE(residents[0].is_single_room);
}

TEST(RemoveResidentTest, RemovesResidentSuccessfully)
{
    Resident residents[100] = {
        {"Ivanov", "I.I.", 1, true},
        {"Petrov", "P.P.", 6, false}};
    int count = 2;

    remove_resident(residents, count, "Ivanov");

    ASSERT_EQ(count, 1);
    EXPECT_EQ(residents[0].surname, "Petrov");
}

TEST(EditResidentTest, EditsResidentData)
{
    Resident residents[100] = {
        {"Ivanov", "I.I.", 1, true},
    };
    int count = 1;

    edit_resident(residents, count, "Ivanov");

    EXPECT_EQ(residents[0].surname, "Новий");
    EXPECT_EQ(residents[0].initials, "Н.Н.");
}

TEST(FindResidentTest, FindsResidentCorrectly)
{
    Resident residents[100] = {
        {"Ivanov", "I.I.", 1, true},
        {"Petrov", "P.P.", 6, false}};
    int count = 2;

    std::ostringstream output;
    std::streambuf *old_cout_buf = std::cout.rdbuf(output.rdbuf());

    find_resident(residents, count, "Petrov");

    std::cout.rdbuf(old_cout_buf);

    std::string result = output.str();
    EXPECT_NE(result.find("Petrov"), std::string::npos);
}

TEST(DisplayAllDataTest, DisplaysAllResidents)
{
    Resident residents[100] = {
        {"Ivanov", "I.I.", 1, true},
        {"Petrov", "P.P.", 6, false}};
    int count = 2;

    std::ostringstream output;
    std::streambuf *old_cout_buf = std::cout.rdbuf(output.rdbuf());

    display_all_data(residents, count);

    std::cout.rdbuf(old_cout_buf);

    std::string result = output.str();
}
