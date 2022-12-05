#include <advent/lib.hpp>

const size_t BUFFER_SZ = 50;
std::filesystem::path startup(int day)
{
    char file_name[BUFFER_SZ] = {0};
    std::snprintf(file_name, BUFFER_SZ - 1, "day_%d.txt", day);
    std::filesystem::path dir("./advent_input");
    std::filesystem::path file(file_name);
    std::cout << dir / file;
    return dir / file;
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
bool open_file(const std::filesystem::path &path, std::fstream &fs)
{
    if (std::filesystem::exists(path))
    {
        fs.open(path);
        return true;
    }
    return false;
}
