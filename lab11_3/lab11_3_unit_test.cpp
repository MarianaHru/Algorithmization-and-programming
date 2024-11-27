#include <gtest/gtest.h>
#include "lab11_3.h"
#include <fstream>

TEST(ResidentsTest, LoadResidentsFromFile)
{
    std::vector<Resident> residents;
    std::string filename = "test_file.txt";

    std::ofstream file(filename);
    file << "Ivanov I.I. 1\nPetrov P.P. 6\n";
    file.close();

    ASSERT_NO_THROW(loadResidents(filename, residents));
    EXPECT_EQ(residents.size(), 2);
    EXPECT_EQ(residents[0].surname, "Ivanov");
    EXPECT_EQ(residents[1].room_number, 6);
}

TEST(ResidentsTest, SaveResidentsToFile)
{
    std::vector<Resident> residents = {
        {"Ivanov", "I.I.", 1},
        {"Petrov", "P.P.", 6},
    };
    std::string filename = "test_save_file.txt";

    ASSERT_NO_THROW(saveResidents(filename, residents));

    std::ifstream file(filename);
    ASSERT_TRUE(file.is_open());

    std::string line1, line2;
    std::getline(file, line1);
    std::getline(file, line2);

    EXPECT_EQ(line1, "Ivanov I.I. 1");
    EXPECT_EQ(line2, "Petrov P.P. 6");

    file.close();
}
TEST(ResidentsTest, FindResident)
{
    std::vector<Resident> residents = {
        {"Ivanov", "I.I.", 1},
        {"Petrov", "P.P.", 6},
    };

    EXPECT_NO_THROW(findResident(residents, "Ivanov"));

    EXPECT_THROW(findResident(residents, "NonExistent"), std::runtime_error);
}

TEST(ResidentsTest, AddResident)
{
    std::vector<Resident> residents;
    Resident newResident = {"Sidorov", "S.S.", 10};
    residents.push_back(newResident);

    EXPECT_EQ(residents.size(), 1);
    EXPECT_EQ(residents[0].surname, "Sidorov");
}
