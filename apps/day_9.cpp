#include <day_9.hpp>


int main()
{
    std::fstream fs;
    auto file_name = startup(DAY);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        std::vector<std::vector<Piece>> board;
        move_rope(fs);
    }
    else
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}
























int move_rope(std::fstream &fs)
{
    RelativePosition curr_pos = RelativePosition::ON;
    int total_tail_moves = 0;
    std::string line;
    while (std::getline(fs, line))
    {
        std::string direction = line.substr(0, line.find(' '));
        std::string count = line.substr(line.find(' '));
        int cnt = std::stoi(count);
        if (direction.front() == 'U')
        {
            auto [tail_moves, new_pos] = do_moves(curr_pos, MoveDirection::UP, cnt);
            total_tail_moves += tail_moves;
            curr_pos = new_pos;
        } else if (direction.front() == 'D')
        {
            auto [tail_moves, new_pos] = do_moves(curr_pos, MoveDirection::DOWN, cnt);
            total_tail_moves += tail_moves;
            curr_pos = new_pos;
        } else if (direction.front() == 'L')
        {
            auto [tail_moves, new_pos] = do_moves(curr_pos, MoveDirection::LEFT, cnt);
            total_tail_moves += tail_moves;
            curr_pos = new_pos;
        } else if (direction.front() == 'R')
        {
            auto [tail_moves, new_pos] = do_moves(curr_pos, MoveDirection::RIGHT, cnt);
            total_tail_moves += tail_moves;
            curr_pos = new_pos;
        }
    }

    std::cout << "Total tail moves: " << total_tail_moves << std::endl;
    return total_tail_moves;
}

std::tuple<int, RelativePosition> do_moves(RelativePosition rpos, MoveDirection md, int cnt)
{
    int tail_moves = 0;
    for (int i = 0; i < cnt; i++)
    {
       // TODO: rename - tail moves
       tail_moves = head_moves_out(rpos, md) ? tail_moves + 1 : tail_moves;
       rpos = get_new_head_position(rpos, md);
    }
    return std::make_tuple(tail_moves, rpos);
}




























// assume - tail is always in the middle, we return the rpos of head to tail
RelativePosition get_new_head_position(RelativePosition rpos, MoveDirection md)
{
    // TODO = review this!!
    // ON
    if (rpos == RelativePosition::ON && md == MoveDirection::UP)
    {
        return RelativePosition::TOP_OF;
    }
    if (rpos == RelativePosition::ON && md == MoveDirection::DOWN)
    {
        return RelativePosition::BOTTOM_OF;
    }
    if (rpos == RelativePosition::ON && md == MoveDirection::LEFT)
    {
        return RelativePosition::LEFT_OF;
    }
    if (rpos == RelativePosition::ON && md == MoveDirection::RIGHT)
    {
        return RelativePosition::RIGHT_OF;
    }
    // TOP OF
    if (rpos == RelativePosition::TOP_OF && md == MoveDirection::UP)
    {
        return RelativePosition::TOP_OF;
    }
    if (rpos == RelativePosition::TOP_OF && md == MoveDirection::DOWN)
    {
        return RelativePosition::ON;
    }
    if (rpos == RelativePosition::TOP_OF && md == MoveDirection::LEFT)
    {
        return RelativePosition::DIAGONAL_TOP_LEFT;
    }
    if (rpos == RelativePosition::TOP_OF && md == MoveDirection::RIGHT)
    {
        return RelativePosition::DIAGONAL_TOP_RIGHT;
    }
    // BOTTOM OF
    if (rpos == RelativePosition::BOTTOM_OF && md == MoveDirection::UP)
    {
        return RelativePosition::ON;
    }
    if (rpos == RelativePosition::BOTTOM_OF && md == MoveDirection::DOWN)
    {
        return RelativePosition::BOTTOM_OF;
    }
    if (rpos == RelativePosition::BOTTOM_OF && md == MoveDirection::LEFT)
    {
        return RelativePosition::DIAGONAL_BOTOM_LEFT;
    }
    if (rpos == RelativePosition::BOTTOM_OF && md == MoveDirection::RIGHT)
    {
        return RelativePosition::DIAGONAL_BOTOM_RIGHT;
    }
    // LEFT OF
    if (rpos == RelativePosition::LEFT_OF && md == MoveDirection::UP)
    {
        return RelativePosition::DIAGONAL_TOP_LEFT;
    }
    if (rpos == RelativePosition::LEFT_OF && md == MoveDirection::DOWN)
    {
        return RelativePosition::DIAGONAL_BOTOM_LEFT;
    }
    if (rpos == RelativePosition::LEFT_OF && md == MoveDirection::LEFT)
    {
        return RelativePosition::LEFT_OF;
    }
    if (rpos == RelativePosition::LEFT_OF && md == MoveDirection::RIGHT)
    {
        return RelativePosition::ON;
    }
    // RIGHT OF
    if (rpos == RelativePosition::RIGHT_OF && md == MoveDirection::UP)
    {
        return RelativePosition::DIAGONAL_TOP_RIGHT;
    }
    if (rpos == RelativePosition::RIGHT_OF && md == MoveDirection::DOWN)
    {
        return RelativePosition::DIAGONAL_BOTOM_RIGHT;
    }
    if (rpos == RelativePosition::RIGHT_OF && md == MoveDirection::LEFT)
    {
        return RelativePosition::ON;
    }
    if (rpos == RelativePosition::RIGHT_OF && md == MoveDirection::RIGHT)
    {
        return RelativePosition::RIGHT_OF;
    }
    // DIAGONAL TOP LEFT
    if (rpos == RelativePosition::DIAGONAL_TOP_LEFT && (md == MoveDirection::UP || md == MoveDirection::RIGHT))
    {
        return RelativePosition::TOP_OF;
    }
    if (rpos == RelativePosition::DIAGONAL_TOP_LEFT && (md == MoveDirection::DOWN || md == MoveDirection::LEFT))
    {
        return RelativePosition::LEFT_OF;
    }
    // DIAGONAL TOP RIGHT
    if (rpos == RelativePosition::DIAGONAL_TOP_RIGHT && (md == MoveDirection::UP || md == MoveDirection::LEFT))
    {
        return RelativePosition::TOP_OF;
    }
    if (rpos == RelativePosition::DIAGONAL_TOP_RIGHT && (md == MoveDirection::DOWN || md == MoveDirection::RIGHT))
    {
        return RelativePosition::RIGHT_OF;
    }
    // DIAGONAL BOTOM LEFT
    if (rpos == RelativePosition::DIAGONAL_BOTOM_LEFT && (md == MoveDirection::UP || md == MoveDirection::LEFT))
    {
        return RelativePosition::LEFT_OF;
    }
    if (rpos == RelativePosition::DIAGONAL_BOTOM_LEFT && (md == MoveDirection::DOWN || md == MoveDirection::RIGHT))
    {
        return RelativePosition::BOTTOM_OF;
    }
    // DIAGONAL BOTOM RIGHT
    if (rpos == RelativePosition::DIAGONAL_BOTOM_RIGHT && (md == MoveDirection::UP || md == MoveDirection::RIGHT))
    {
        return RelativePosition::RIGHT_OF;
    }
    if (rpos == RelativePosition::DIAGONAL_BOTOM_RIGHT && (md == MoveDirection::UP || md == MoveDirection::RIGHT))
    {
        return RelativePosition::BOTTOM_OF;
    }

    return RelativePosition::UNKNOWN;
}

// check if the head piece is moving away from tail (tail should move)
bool head_moves_out(RelativePosition rpos, MoveDirection md)
{
    // gaurds for +
    if (rpos == RelativePosition::LEFT_OF && md == MoveDirection::LEFT)
    {
        return true;
    }
    if (rpos == RelativePosition::RIGHT_OF && md == MoveDirection::RIGHT)
    {
        return true;
    }
    if (rpos == RelativePosition::TOP_OF && md == MoveDirection::UP)
    {
        return true;
    }
    if (rpos == RelativePosition::BOTTOM_OF && md == MoveDirection::DOWN)
    {
        return true;
    }
    // guards for X 
    if (rpos == RelativePosition::DIAGONAL_TOP_LEFT &&
    (md == MoveDirection::LEFT || md == MoveDirection::UP))
    {
        return true;
    }
    if (rpos == RelativePosition::DIAGONAL_TOP_RIGHT &&
    (md == MoveDirection::RIGHT || md == MoveDirection::UP))
    {
        return true;
    }
    if (rpos == RelativePosition::DIAGONAL_BOTOM_LEFT &&
    (md == MoveDirection::LEFT || md == MoveDirection::DOWN))
    {
        return true;
    }
    if (rpos == RelativePosition::DIAGONAL_BOTOM_RIGHT &&
    (md == MoveDirection::RIGHT || md == MoveDirection::DOWN))
    {
        return true;
    }

    return false;
}
