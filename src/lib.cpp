#include <advent/lib.hpp>

const int BUFFER_SZ = 250;
std::string startup(int day)
{
    char buffer[BUFFER_SZ] = {0};
    // sizeof op?
    std::snprintf(buffer, BUFFER_SZ - 1, "./advent_input/day_%d.txt", day);

    return std::string(buffer);
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
