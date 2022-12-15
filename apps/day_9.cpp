#include <day_9.hpp>


int main()
{
    std::fstream fs;
    auto file_name = startup(DAY);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}

// TODO: do we even need a board???

// setup_board
std::vector<std::vector<Piece>> setup_board()
{
    // create a 3x3 board with HEAD_TAIL in the center
    std::vector<std::vector<Piece>> board;
    for (int i = 0; i < BOARD_SZ; i++)
    {
        std::vector<Piece> board_row;
        for (int j = 0; j < BOARD_SZ; j++)
        {
            if (i == 1 && j == 1)
            {
                board_row.push_back(Piece::HEAD_TAIL);
            }
            else 
            {
                board_row.push_back(Piece::EMPTY);
            }
        }
    }
    return board;
}

// process_move
bool process_move(std::vector<std::vector<Piece>> board, MoveDirection md)
{
    if (head_moves_out(board, md))
    {
        board = update_board(board, md);
        return true;
    }
    return false;
}
// returns a bool if tail moved as a result
std::vector<std::vector<Piece>> update_board(std::vector<std::vector<Piece>> board, MoveDirection md)
{
    // TODO - update board should determine new TAIL HEAD orientation

    return board;
}

RelativePosition get_new_head_position(std::vector<std::vector<Piece>> board, MoveDirection md)
{
    RelativePosition curr_pos = get_head_tail_orientation(board);
    // ON
    if (curr_pos == ON && md == MoveDirection::UP)
    {
        return RelativePosition::TOP_OF;
    }
    if (curr_pos == RelativePosition::ON && md == MoveDirection::DOWN)
    {
        return RelativePosition::BOTTOM_OF;
    }
    if 
}

// get_head_tail_orientation()
// ASSUME: Tail is always in center
RelativePosition get_head_tail_orientation(std::vector<std::vector<Piece>> board)
{
    // check L | R (no diag)
    if (board[CENTER + 1][CENTER] == Piece::HEAD)
    {
        return RelativePosition::RIGHT_OF;
    }
    if (board[CENTER - 1][CENTER] == Piece::HEAD)
    {
        return RelativePosition::LEFT_OF;
    }
    if (board[CENTER][CENTER + 1] == Piece::HEAD)
    {
        return RelativePosition::BOTTOM_OF;
    }
    if (board[CENTER][CENTER - 1] == Piece::HEAD)
    {
        return RelativePosition::TOP_OF;
    }
    if (board[CENTER - 1][CENTER - 1] == Piece::HEAD)
    {
        return RelativePosition::DIAGONAL_TOP_LEFT;
    }
    if (board[CENTER - 1][CENTER + 1] == Piece::HEAD)
    {
        return RelativePosition::DIAGONAL_TOP_RIGHT;
    }
    if (board[CENTER + 1][CENTER - 1] == Piece::HEAD)
    {
        return RelativePosition::DIAGONAL_BOTOM_LEFT;
    }
    if (board[CENTER + 1][CENTER + 1] == Piece::HEAD)
    {
        return RelativePosition::DIAGONAL_BOTOM_RIGHT;
    }

    return RelativePosition::ON;
}



// head_moves_out()
// check if the head piece is moving away from tail (tail should move)
bool head_moves_out(std::vector<std::vector<Piece>> board, MoveDirection md)
{
    // gaurds for +
    if (get_head_tail_orientation(board) == RelativePosition::LEFT_OF && md == MoveDirection::LEFT)
    {
        return true;
    }
    if (get_head_tail_orientation(board) == RelativePosition::RIGHT_OF && md == MoveDirection::RIGHT)
    {
        return true;
    }
    if (get_head_tail_orientation(board) == RelativePosition::TOP_OF && md == MoveDirection::UP)
    {
        return true;
    }
    if (get_head_tail_orientation(board) == RelativePosition::BOTTOM_OF && md == MoveDirection::DOWN)
    {
        return true;
    }
    // guards for X 
    if (get_head_tail_orientation(board) == RelativePosition::DIAGONAL_TOP_LEFT &&
    (md == MoveDirection::LEFT || md == MoveDirection::UP))
    {
        return true;
    }
    if (get_head_tail_orientation(board) == RelativePosition::DIAGONAL_TOP_RIGHT &&
    (md == MoveDirection::RIGHT || md == MoveDirection::UP))
    {
        return true;
    }
    if (get_head_tail_orientation(board) == RelativePosition::DIAGONAL_BOTOM_LEFT &&
    (md == MoveDirection::LEFT || md == MoveDirection::DOWN))
    {
        return true;
    }
    if (get_head_tail_orientation(board) == RelativePosition::DIAGONAL_BOTOM_RIGHT &&
    (md == MoveDirection::RIGHT || md == MoveDirection::DOWN))
    {
        return true;
    }

    return false;
}

// check if the head piece is moving toward tail (tail does not move)
// return (x,y) for board[y][x]
std::vector<int> get_head_pos(std::vector<std::vector<Piece>> board)
{
    for (int y = 0; y < BOARD_SZ; y++)
    {
        for (int x = 0; x < BOARD_SZ; x++)
        {
            if (board[y][x] == Piece::HEAD || board[y][x] == Piece::HEAD_TAIL)
            {
                return std::vector<int>{x,y};
            }
        }
    }
    return std::vector<int>{-1, -1};
}
    
