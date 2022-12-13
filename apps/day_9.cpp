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
// returns a bool if tail moved as a result

// update_board()
// given the Piece, move that piece to the coordinates

std::vector<std::vector<Piece>> update_board(std::vector<std::vector<Piece>> board, Piece p, int x, int y)
{
    
}

// get_head_tail_orientation()

// head_moves_out()
// check if the head piece is moving away from tail (tail should move)

// head_moves_in()
// check if the head piece is moving toward tail (tail does not move)
