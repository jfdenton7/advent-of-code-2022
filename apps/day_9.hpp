#pragma once
#ifndef __DAY_9__HPP
#define __DAY_9_HPP

#include <advent/lib.hpp>

#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>

const int DAY = 9;

const int BOARD_SZ = 3;
const int CENTER = 1;

enum MoveDirection
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum RelativePosition
{
    ON,
    TOP_OF,
    BOTTOM_OF,
    LEFT_OF,
    RIGHT_OF,
    DIAGONAL_TOP_LEFT,
    DIAGONAL_TOP_RIGHT,
    DIAGONAL_BOTOM_LEFT,
    DIAGONAL_BOTOM_RIGHT
};

enum Piece
{
    HEAD,
    TAIL,
    HEAD_TAIL, // Head covers Tails
    EMPTY
};

std::vector<std::vector<Piece>> setup_board();
std::vector<int> get_head_pos(std::vector<std::vector<Piece>> board);
RelativePosition get_head_tail_orientation(std::vector<std::vector<Piece>> board);
bool head_moves_out(std::vector<std::vector<Piece>> board, MoveDirection md);
std::vector<std::vector<Piece>> update_board(std::vector<std::vector<Piece>> board, MoveDirection md);
RelativePosition get_new_head_position(std::vector<std::vector<Piece>> board, MoveDirection md);

#endif // !__DAY_9__HPP
