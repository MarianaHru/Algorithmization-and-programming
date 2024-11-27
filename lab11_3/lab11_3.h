#ifndef LAB11_3_H
#define LAB11_3_H

#include <string>
#include <vector>

struct Resident
{
    std::string surname;
    std::string initials;
    int room_number;
};

void loadResidents(const std::string &filename, std::vector<Resident> &residents);
void findResident(const std::vector<Resident> &residents, const std::string &surname);
void addResident(std::vector<Resident> &residents);
void displayResidents(const std::vector<Resident> &residents);
void saveResidents(const std::string &filename, const std::vector<Resident> &residents);

#endif
