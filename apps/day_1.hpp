#pragma once
#ifndef __DAY_1_HPP
#define __DAY_1_HPP
#include <advent/lib.hpp>

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

struct elf
{
    int elf_position;
    int elf_calories;
};

void add_elf_to_deque(elf elf, std::deque<struct elf> &deq);

void elf_calories(std::fstream &fs);

#endif