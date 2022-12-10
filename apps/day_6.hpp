#pragma once
#ifndef __DAY_6_HPP

#include <advent/lib.hpp>

#include <iostream>
#include <fstream>
#include <set>

const int DAY = 6;
const int MARKER_SIZE_P1 = 4;
const int MARKER_SIZE_P2 = 14;

bool is_unique(std::string s);
int find_marker(std::string marker, int marker_size);

#endif // !__DAY_6_HPP
