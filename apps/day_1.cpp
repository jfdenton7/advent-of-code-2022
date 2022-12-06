#include <day_1.hpp>

int main()
{
    std::fstream fs;
    auto file_name = startup(DAY);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        elf_calories(fs);
    }
    else
    {
        cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}

void elf_calories(std::fstream &fs)
{

    std::string line;
    std::vector<int> calories;
    int current_elf = 1;
    int current_total_calories = 0;
    while (std::getline(fs, line))
    {
        if (line == "")
        {
            calories.push_back(current_total_calories);
            current_elf++;
            current_total_calories = 0;
            continue;
        }

        try
        {
            trim(line);
            current_total_calories += std::stoi(line);
        }
        catch (std::invalid_argument &e)
        {
            cout << e.what() << std::endl;
        }
    }

    std::sort(calories.begin(), calories.end());
    int max_calories = calories.back();
    int top_three = std::reduce(calories.rbegin(), calories.rbegin() + 3, 0, std::plus<int>());
    cout << "max calories is: " << max_calories << "\n";
    cout << "top 3 total is: " << top_three << std::endl;
}