#ifndef LAB12_4_H
#define LAB12_4_H

#include <string>

struct Resident
{
    char surname[50];
    char initials[10];
    int room_number;
    bool is_single_room;
};

void addResident(const std::string &filename);
void displayResidents(const std::string &filename);
bool findResident(const std::string &filename, const std::string &surname, Resident &result);
void editResident(const std::string &filename, const std::string &surname);
void deleteResident(const std::string &filename, const std::string &surname);

#endif
