#pragma once
#ifndef __DAY_3_HPP
#define __DAY_3_HPP

#include <advent/lib.hpp>

#include <vector>
#include <set>
#include <string>
#include <tuple>
#include <locale>
#include <iostream>
#include <fstream>
#include <filesystem>

class Rucksack
{
public:
    Rucksack(std::string &sack);
    int priority();

private:
    int priority_sum;
    std::vector<std::string> compartments;
    int item_priority(char item);

    const int LOWER_OFF = 96;
    const int UPPER_OFF = 64;
};

class Storage
{
public:
    Storage(std::fstream &fs);
    ~Storage();
    int storage_priority;
private:
    std::vector<Rucksack*> rucksacks;
};


#endif