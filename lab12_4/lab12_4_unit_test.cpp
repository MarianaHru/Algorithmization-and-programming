#include "lab12_4.h"
#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

class ResidentManagerTest : public ::testing::Test
{
protected:
    std::string testFile = "test_residents.dat";

    void SetUp() override
    {

        std::ofstream file(testFile, std::ios::binary);
        file.close();
    }

    void TearDown() override
    {

        std::remove(testFile.c_str());
    }

    void writeResident(const Resident &resident)
    {
        std::ofstream file(testFile, std::ios::binary | std::ios::app);
        file.write(reinterpret_cast<const char *>(&resident), sizeof(Resident));
        file.close();
    }

    Resident createResident(const std::string &surname, const std::string &initials, int room_number, bool is_single_room)
    {
        Resident resident;
        strncpy(resident.surname, surname.c_str(), sizeof(resident.surname));
        strncpy(resident.initials, initials.c_str(), sizeof(resident.initials));
        resident.room_number = room_number;
        resident.is_single_room = is_single_room;
        return resident;
    }
};

TEST_F(ResidentManagerTest, AddResidentTest)
{
    std::string testSurname = "Ivanov";
    std::string testInitials = "I.I.";
    int testRoomNumber = 5;
    bool testIsSingleRoom = true;

    Resident resident = createResident(testSurname, testInitials, testRoomNumber, testIsSingleRoom);
    writeResident(resident);

    std::ifstream file(testFile, std::ios::binary);
    Resident readResident;
    ASSERT_TRUE(file.read(reinterpret_cast<char *>(&readResident), sizeof(Resident)));
    EXPECT_STREQ(readResident.surname, testSurname.c_str());
    EXPECT_STREQ(readResident.initials, testInitials.c_str());
    EXPECT_EQ(readResident.room_number, testRoomNumber);
    EXPECT_EQ(readResident.is_single_room, testIsSingleRoom);
    file.close();
}

TEST_F(ResidentManagerTest, FindResidentTest)
{
    Resident resident1 = createResident("Ivanov", "I.I.", 5, true);
    Resident resident2 = createResident("Petrov", "P.P.", 10, false);
    writeResident(resident1);
    writeResident(resident2);

    Resident result;
    EXPECT_TRUE(findResident(testFile, "Petrov", result));
    EXPECT_STREQ(result.surname, "Petrov");
    EXPECT_STREQ(result.initials, "P.P.");
    EXPECT_EQ(result.room_number, 10);
    EXPECT_FALSE(result.is_single_room);
}

TEST_F(ResidentManagerTest, EditResidentTest)
{
    Resident resident = createResident("Ivanov", "I.I.", 5, true);
    writeResident(resident);

    editResident(testFile, "Ivanov");

    std::ifstream file(testFile, std::ios::binary);
    Resident updatedResident;
    ASSERT_TRUE(file.read(reinterpret_cast<char *>(&updatedResident), sizeof(Resident)));
    EXPECT_STRNE(updatedResident.surname, "Ivanov");
    file.close();
}

TEST_F(ResidentManagerTest, DeleteResidentTest)
{
    Resident resident1 = createResident("Ivanov", "I.I.", 5, true);
    Resident resident2 = createResident("Petrov", "P.P.", 10, false);
    writeResident(resident1);
    writeResident(resident2);

    deleteResident(testFile, "Ivanov");

    std::ifstream file(testFile, std::ios::binary);
    Resident remainingResident;
    ASSERT_TRUE(file.read(reinterpret_cast<char *>(&remainingResident), sizeof(Resident)));
    EXPECT_STREQ(remainingResident.surname, "Petrov");
    file.close();
}
