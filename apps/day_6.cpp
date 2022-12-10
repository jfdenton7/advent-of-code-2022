#include <day_6.hpp>

int main() 
{
    std::fstream fs;
    auto file_name = startup(DAY);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        std::string marker;
        std::getline(fs, marker);
        std::cout << "P1 marker: " << find_marker(marker, MARKER_SIZE_P1) << "\n";
        std::cout << "P2 marker: " << find_marker(marker, MARKER_SIZE_P2) << std::endl;
    }
    else
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}

int find_marker(std::string marker, int marker_sz)
{
    int mark_begin = 0;
    while (mark_begin + marker_sz < marker.size())
    {
        if (is_unique(marker.substr(mark_begin, marker_sz)))
        {
            return mark_begin + marker_sz;
        }
        mark_begin++;
    }
    return -1;
}


bool is_unique(std::string s)
{
    std::set<char> chars;
    for (char c : s) 
    {
        if (chars.count(c))
        {
            return false;
        }
        chars.insert(c);
    }
    return true;
}
