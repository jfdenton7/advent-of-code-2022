#pragma once
#ifndef __DAY_4_HPP
#define __DAY_4_HPP

#include <advent/lib.hpp>

#include <fstream>
#include <iostream>
#include <string>

const int DAY = 4;

class Range {
public:
	int upper;
	int lower;
	Range();
	bool contains(Range r);
	bool overlaps(Range r);
	void set_range(std::string assignment);
};

std::vector<int> parse_ranges(std::fstream& fs);

#endif // !__DAY_4_HPP
