#include <advent/lib.hpp>

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
