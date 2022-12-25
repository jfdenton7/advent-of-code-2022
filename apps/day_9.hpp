#pragma once
#ifndef __DAY_9__HPP
#define __DAY_9_HPP

#include <advent/lib.hpp>

#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>

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

// 49x49
enum Piece
{
    HEAD_TAIL,
    TAIL,
    HEAD,
    EMPTY
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
    DIAGONAL_BOTOM_RIGHT,
    UNKNOWN
};

int move_rope(std::fstream &fs);
std::tuple<int, RelativePosition> do_moves(RelativePosition rpos, MoveDirection md, int cnt);
// std::tuple<bool, RelativePosition> process_move(RelativePosition pos, MoveDirection md);
bool head_moves_out(RelativePosition rpos, MoveDirection md);
RelativePosition get_new_head_position(RelativePosition rpos, MoveDirection md);

#endif // !__DAY_9__HPP
