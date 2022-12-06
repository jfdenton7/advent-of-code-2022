#include <day_4.hpp>

int main() 
{
    std::fstream fs;
    auto file_name = startup(DAY);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        auto v = parse_ranges(fs);
        std::cout << "total contained inside: " << v.front() << std::endl;
        std::cout << "total overlapping: " << v.back() << std::endl;
    }
    else
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}

std::vector<int> parse_ranges(std::fstream& fs)
{
    std::string assignment_pair;
    int total_contain_fully = 0;
    int total_overlap = 0;
    while (std::getline(fs, assignment_pair))
    {
		std::string assignment_delim(",");
		auto v = ssplit_on(assignment_pair, assignment_delim);
		Range r1;
		Range r2;
		r1.set_range(v.front());
		r2.set_range(v.back());
        total_overlap = (r1.overlaps(r2) || r2.overlaps(r1)) ? total_overlap + 1 : total_overlap;
        total_contain_fully = (r1.contains(r2) || r2.contains(r1)) ? total_contain_fully + 1 : total_contain_fully;
    }
    return std::vector<int>{total_contain_fully, total_overlap};
}

Range::Range()
{
    this->upper = 0;
    this->lower = 0;
}

void Range::set_range(std::string assignment)
{
    auto v = ssplit_on(assignment, std::string("-"));
    try 
    {
        this->lower = std::stoi(v.front());
        this->upper = std::stoi(v.back());
    }
    catch (std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }
}

bool Range::contains(Range r)
{
    // lower boundary must be >= "this" boundary
    // AND
    // upper boundary must be <= "this" boundary
    if (r.lower >= this->lower && r.upper <= this->upper) 
    {
        return true;
    }
    return false;
}

bool Range::overlaps(Range r) {


    // if the boundaries cross at all! (OR!)
    if ((r.lower >= this->lower && r.lower <= this->upper)|| (r.upper <= this->upper && r.upper >= this->lower))
    {
        return true;
    }
    return false;

}
