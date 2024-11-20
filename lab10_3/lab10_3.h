#ifndef LAB10_3_H
#define LAB10_3_H

#include <string>

struct Resident
{
    std::string surname;
    std::string initials;
    int room_number;
    bool is_single_room;
};

void add_resident(Resident residents[], int &count, int room_number, bool is_single_room);
void remove_resident(Resident residents[], int &count, const std::string &surname);
void edit_resident(Resident residents[], int count, const std::string &surname);
void find_resident(const Resident residents[], int count, const std::string &surname);
void display_all_data(const Resident residents[], int count);

#endif
