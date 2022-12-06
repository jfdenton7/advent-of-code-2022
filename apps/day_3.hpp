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
#include <stdexcept>

const int DAY = 3;

class Rucksack
{
public:
    Rucksack(std::string &sack);
    int priority();
    std::set<char> get_unique();

private:
    int priority_sum;
    std::string rucksack;
    std::vector<std::string> compartments;
};

class Storage
{
public:
    Storage(std::fstream &fs);
    int storage_priority;
    int total_badge_priority;
private:
};

class BadgeGroup
{
public:
    BadgeGroup(std::vector<Rucksack*> group);
    ~BadgeGroup();
    char get_badge_item();
private:
    std::vector<Rucksack*> group;
};

int item_priority(char item);
const int LOWER_OFF = 96;
const int UPPER_OFF = 64;

#endif