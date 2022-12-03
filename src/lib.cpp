#include <advent/lib.hpp>

std::string startup()
{
    std::string file_name;
    std::cout
        << "Path to input file (^D to default: \"./advent_input/day_1.txt\"): " << std::endl;

    if (!(std::cin >> file_name))
    {
        file_name = "./advent_input/day_1.txt";
    }
    return file_name;
}

//  =========== STRING UTILS =========== //
void ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                    { return !std::isspace(ch); }));
}

void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); })
                .base(), // base() reverses the iterator!
            s.end());
}

void trim(std::string &s)
{
    // https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
    ltrim(s);
    rtrim(s);
}

//  =========== FILE IO =========== //
bool open_file(std::string &file, std::fstream &fs)
{
    if (std::filesystem::exists(file))
    {
        fs.open(file);
        return true;
    }
    return false;
}
