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

enum MoveDirection
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum RelativePosition
{
    BOTTOM,
    ABOVE,
    LEFT,
    RIGHT
};

enum Piece
{
    HEAD,
    TAIL,
    HEAD_TAIL, // Head covers Tails
    EMPTY
};

std::vector<std::vector<Piece>> setup_board();
std::vector<std::vector<Piece>> update_board(std::vector<std::vector<Piece>> board, Piece p, int x, int y);

#endif // !__DAY_9__HPP
