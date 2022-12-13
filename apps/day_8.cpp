#include <day_8.hpp>

int main()
{
    std::fstream fs;
    auto file_name = startup(DAY);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        // 99 x 99 forest (square)
        auto [forest, visible] = parse_input(fs);
        visible = find_visible_trees(forest, visible);

        int vis_tree_cnt = 0;
        int max_scenic_score = -1;
        for (int y = 0; y < forest.size(); y++)
        {
            for (int x = 0; x < forest[y].size(); x++)
            {
                if (visible[y][x])
                {
                    vis_tree_cnt++;
                }
                int score = calculate_scenic_score(forest, x, y);
                if (score > max_scenic_score)
                {
                    max_scenic_score = score;
                }
            }
        }
        std::cout << "TOTAL VIS TREES IS: " << vis_tree_cnt << "\n";
        std::cout << "MAX SCENIC SCORE: " << max_scenic_score << std::endl;
    }
    else
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}

std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<bool>>> parse_input(std::fstream& fs)
{
    std::string line;
    std::vector<std::vector<int>> forest;
    std::vector<std::vector<bool>> visible;
    while (std::getline(fs, line))
    {
        std::vector<int> tree_line;
        std::vector<bool> visible_line;
        for (char c : line)
        {
            tree_line.push_back(c - '0');
            visible_line.push_back(false);
        }
        forest.push_back(tree_line);
        visible.push_back(visible_line);
    }
    return std::make_tuple(forest, visible);
}

std::vector<std::vector<bool>> find_visible_trees(std::vector<std::vector<int>> forest, std::vector<std::vector<bool>> visible)
{
    for (int y = 0; y < forest.size(); y++)
    {
        for (int x = 0; x < forest[y].size(); x++)
        {
            visible[y][x] = is_visible(forest, x, y);
        }
    }
    return visible;
}

bool is_visible(std::vector<std::vector<int>> forest, int x, int y)
{
    return is_visible_on_line(forest, x, y, Direction::EAST) ||
        is_visible_on_line(forest, x, y, Direction::WEST) ||
        is_visible_on_line(forest, x, y, Direction::NORTH) ||
        is_visible_on_line(forest, x, y, Direction::SOUTH);

}

int calculate_scenic_score(std::vector<std::vector<int>> forest, int x, int y)
{
    return visual_score_on_line(forest, x, y, Direction::EAST) * 
        visual_score_on_line(forest, x, y, Direction::WEST) * 
        visual_score_on_line(forest, x, y, Direction::NORTH) * 
        visual_score_on_line(forest, x, y, Direction::SOUTH);
}

int visual_score_on_line(std::vector<std::vector<int>> forest, int x, int y, Direction d)
{
    int visual_score = 0;
    switch (d)
    {
        case Direction::NORTH:
            for (int row = y - 1; row >= 0; row--)
            {
                if (forest[row][x] < forest[y][x])
                {
                    visual_score++;
                }
                else if (forest[row][x] >= forest[y][x])
                {
                    visual_score++;
                    break;
                }
            }
            return visual_score;
        case Direction::SOUTH:
            for (int row = y + 1; row < forest.size(); row++)
            {
                if (forest[row][x] < forest[y][x])
                {
                    visual_score++;
                }
                else if (forest[row][x] >= forest[y][x])
                {
                    visual_score++;
                    break;
                }
            }
            return visual_score;
        case Direction::EAST:
            for (int col = x + 1; col < forest[y].size(); col++)
            {
                if (forest[y][col] < forest[y][x])
                {
                    visual_score++;
                }
                else if (forest[y][col] >= forest[y][x])
                {
                    visual_score++;
                    break;
                }
            }
            return visual_score;
        case Direction::WEST:
            for (int col = x - 1; col >= 0; col--)
            {
                if (forest[y][col] < forest[y][x])
                {
                    visual_score++;
                }
                else if (forest[y][col] >= forest[y][x])
                {
                    visual_score++;
                    break;
                }
            }
            return visual_score;
        default:
            std::cout << "ERROR: NOT A DIRECTION" << std::endl;
            return false;
    }
}



bool is_visible_on_line(std::vector<std::vector<int>> forest, int x, int y, Direction d)
{
    switch (d) {
        case Direction::NORTH:
            for (int row = 0; row < y; row++)
            {
                if (forest[row][x] >= forest[y][x])
                {
                    return false;
                }
            }
            return true;
        case Direction::SOUTH:
            for (int row = forest.size() - 1; row > y; row--)
            {
                if (forest[row][x] >= forest[y][x])
                {
                    return false;
                }
            }
            return true;
        case Direction::EAST:
            for (int col = 0; col < x; col++)
            {
                if (forest[y][col] >= forest[y][x])
                {
                    return false;
                }
            }
            return true;
        case Direction::WEST:
            for (int col = forest[y].size() - 1; col > x; col--)
            {
                if (forest[y][col] >= forest[y][x])
                {
                    return false;
                }
            }
            return true;
        default:
            std::cout << "ERROR: NOT A DIRECTION" << std::endl;
            return false;
    }
}
