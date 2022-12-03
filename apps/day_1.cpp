#include <day_1.hpp>

int main()
{
    std::fstream fs;
    auto file_name = startup();
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        elf_calories(fs);
    }
    else
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}

void add_elf_to_deque(elf elf, std::deque<struct elf> &elves)
{
    // no max elf calories
    if (elves.size() == 0)
    {
        elves.push_front(elf);
    }
    // new largest elf
    else if (elf.elf_calories > elves[0].elf_calories)
    {
        elves.push_front(elf);
    }
    // not a large elf
    else
    {
        elves.push_back(elf);
    }
}

void elf_calories(std::fstream &fs)
{

    std::deque<struct elf> elves;
    std::string line;
    std::vector<int> calories;
    int current_elf = 1;
    int current_total_calories = 0;
    while (std::getline(fs, line))
    {
        // std::cout << line << "\n";

        if (line == "")
        {
            add_elf_to_deque(
                elf{
                    elf_position : current_elf,
                    elf_calories : current_total_calories
                },
                elves);
            // do not process empty line, move to next elf
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
            std::cout << e.what() << std::endl;
        }
    }

    std::sort(calories.begin(), calories.end());
    for (auto cal : std::vector<int>(calories.rbegin(), calories.rbegin() + 3))
    {
        std::cout << cal << "\n";
    }

    std::cout << "max calorie elf is: " << elves[0].elf_position << "\n";
    std::cout << "max calories is: " << elves[0].elf_calories << "\n";
    // part 2
    // find the top 3
    std::cout << "2nd elf calories is: " << elves[1].elf_calories << "\n";
    std::cout << "2nd elf position is: " << elves[1].elf_position << "\n";
    std::cout << "3rd elf calories is: " << elves[2].elf_calories << "\n";
    std::cout << "3rd elf position is: " << elves[2].elf_position << "\n";

    std::cout << "total of top 3 is: " << elves[0].elf_calories + elves[1].elf_calories + elves[2].elf_calories << std::endl;
}