#include <day_5.hpp>

int main()
{    
    std::fstream fs;
    auto file_name = startup(DAY);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        std::vector<std::string> layout = get_shipyard_layout(fs);
        std::vector<std::stack<char>> shipyard = create_shipyard(layout);
        std::vector<Move> moves = generate_move_list(fs);
        shipyard = do_moves(moves, shipyard);
        print_tops(shipyard);

        std::vector<std::stack<char>> shipyard_ordered = create_shipyard(layout);
        shipyard_ordered = do_ordered_moves(moves, shipyard_ordered);
        print_tops(shipyard_ordered);
    }
    else
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}

 std::vector<std::stack<char>> do_moves(std::vector<Move> moves, std::vector<std::stack<char>> shipyard)
{
    for (Move move : moves)
    {
        for (int moved = 0; moved < move.cnt; moved++)
        {
            shipyard = do_move(move.from, move.to, shipyard);
        }
    }
    return shipyard;
}

std::vector<std::stack<char>> do_ordered_moves(std::vector<Move> moves, std::vector<std::stack<char>> shipyard)
{
    for (Move move : moves)
    {
        // we want to keep the order, so top/pop throw in vec, reverse then push
        std::vector<char> chunk;
        for (int moved = 0; moved < move.cnt; moved++)
        {
            char crate = shipyard[move.from - 1].top();
            shipyard[move.from - 1].pop();
            chunk.push_back(crate);
        }
        std::vector<char> rev_chunk(chunk.rbegin(), chunk.rend());
        for (char crate : rev_chunk) {
            shipyard[move.to - 1].push(crate);
        }
    }
    return shipyard;
}

std::vector<std::stack<char>> do_move(int from, int to, std::vector<std::stack<char>> shipyard)
{
    char crate = shipyard[from - 1].top();
    shipyard[from - 1].pop();
    shipyard[to - 1].push(crate);
    return shipyard;
}

void print_tops(std::vector<std::stack<char>> shipyard)
{
    for (std::stack<char> crates : shipyard)
    {
        std::cout << crates.top();
    }
    std::cout << std::endl;
}

// return the inverted layout (for easier parsing)
std::vector<std::string> get_shipyard_layout(std::fstream& fs)
{
    std::string line;
    std::vector<std::string> layout;
    while (std::getline(fs, line))
    {
        // HIT position right before move list
        if (line == "")
        {
            break;
        }
        layout.push_back(line);
    }
    return std::vector<std::string>(layout.rbegin(), layout.rend());
}

// generate the move list for the crane
std::vector<Move> generate_move_list(std::fstream& fs)
{
    std::vector<Move> move_list;
    // assume the file pointer has stopped right before move list
    std::string move;
    const std::regex move_match("move ([0-9]+) from ([0-9]+) to ([0-9]+)");
    std::smatch match;
    while (std::getline(fs, move))
    {
        std::regex_match(move, match, move_match);
        if (match.size() == 4) 
        {
            Move m;
            m.cnt = std::stoi(match[1]);
            m.from = std::stoi(match[2]);
            m.to = std::stoi(match[3]);
            move_list.push_back(m);
        }
        else
        {
            std::cout << "FAIL!";
        }
    }
    return move_list;
}

// create the shipyard
std::vector<std::stack<char>> create_shipyard(std::vector<std::string> layout)
{
    // TODO - with inverted layout, create the initial setup of the shipyard

    /* PLAN
    * - grab 3 chars
    * - check if 1st char is '['
    * - if so --> move to next, store as crate
    * - else --> move to next 3

    NOTE: when move to next, jump 1 white space
    - do this via seekg and tellg (add +1)
    */
    std::vector<std::stack<char>> shipyard = setup_stacks(layout[0]);
    // for (std::string crates : layout.begin() + 1)
    std::for_each(layout.begin() + 1, layout.end(), [&](std::string &s) {
        // shipyard
        std::istringstream ss(s);
        int index = 0;
        while (!ss.eof())
        {
            std::string s = grab_and_jump(ss, 3, 1);
            std::cout << s << "\n";
            if (s[1] != ' ')
            {
                shipyard[index].push(s[1]);
            }
            index++;
        }
    });
    return shipyard;
}

// reads the index line
std::vector<std::stack<char>> setup_stacks(std::string& s)
{
    std::vector<std::stack<char>> shipyard;
    std::istringstream ss(s);
    while (!ss.eof())
    {
        std::string s = grab_and_jump(ss, 3, 1);
        std::cout << s << "\n";
        shipyard.push_back(std::stack<char>());
    }
    return shipyard;
}
