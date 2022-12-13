#pragma once
#ifndef __DAY_8__HPP
#define __DAY_8_HPP

#include <advent/lib.hpp>

#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>

enum Direction
{
    NORTH,
    SOUTH,
    EAST,
    WEST
};

const int DAY = 8;

std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<bool>>> parse_input(std::fstream& fs);
bool is_visible(std::vector<std::vector<int>> forest, int x, int y);
bool is_visible_on_line(std::vector<std::vector<int>> forest, int x, int y, Direction d);
int calculate_scenic_score(std::vector<std::vector<int>> forest, int x, int y);
int visual_score_on_line(std::vector<std::vector<int>> forest, int x, int y, Direction d);
std::vector<std::vector<bool>> find_visible_trees(std::vector<std::vector<int>> forest, std::vector<std::vector<bool>> visible);

#endif // !__DAY_8__HPP
