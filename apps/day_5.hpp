#pragma once
#ifndef __DAY_5_HPP
#define __DAY_5_HPP

#include <advent/lib.hpp>

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <regex>
#include <sstream>

const int DAY = 5;

struct Move {
    int cnt;
    int from;
    int to;
};

std::vector<std::stack<char>> create_shipyard(std::vector<std::string> layout);
std::vector<std::stack<char>> setup_stacks(std::string &s);
std::vector<std::stack<char>> add_crates(std::fstream &fs);
std::vector<std::string> get_shipyard_layout(std::fstream &fs);
std::vector<Move> generate_move_list(std::fstream &fs);

std::vector<std::stack<char>> do_moves(std::vector<Move> moves, std::vector<std::stack<char>> shipyard);
std::vector<std::stack<char>> do_ordered_moves(std::vector<Move> moves, std::vector<std::stack<char>> shipyard);
std::vector<std::stack<char>> do_move(int from, int to, std::vector<std::stack<char>> shipyard);
void print_tops(std::vector<std::stack<char>> shipyard);

#endif // !__DAY_5_HPP
