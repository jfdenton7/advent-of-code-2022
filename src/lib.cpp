#include <advent/lib.hpp>

const size_t BUFFER_SZ = 50;
std::filesystem::path startup(int day)
{
    // TODO - need to somehow get this hooked in....
	// "C:\Users\Josiah\source\repos\advent - of - code - 2022\advent_input\day_3.txt"
    char file_name[BUFFER_SZ] = {0};
    std::snprintf(file_name, BUFFER_SZ - 1, "day_%d.txt", day);
    fs::path file(file_name);
    std::cout << fs::current_path() / file;
    return fs::current_path() / file;
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

std::vector<std::string> ssplit_on(std::string& s, std::string& delim)
{
    size_t split_pos = s.find(delim);
    auto split_1 = s.substr(0, split_pos);
    auto split_2 = s.substr(split_pos + delim.size(), s.size() - delim.size() - split_1.size());
    return std::vector<std::string>{split_1, split_2};
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
