#include <advent/lib.hpp>

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>

int elf_calories();

int main()
{
    if (std::filesystem::exists("./advent_input/day_1.txt"))
    {
        return elf_calories();
    }
    else
    {
        std::cout << "failed";
        return -1;
    }
}

int elf_calories()
{
    std::string file_name = "./advent_input/day_1.txt";

    // this crates an fstream with default value
    std::fstream fs;
    fs.open(file_name);

    std::string line;
    // this approach removes whitespace
    // while (fs >> line)
    // {
    //     std::cout << line << std::endl;
    // }
    int current_elf = 1;
    int current_total_calories = 0;
    int max_calories = 0;
    int max_calories_elf = 0;
    while (std::getline(fs, line))
    {

        if (line == "" && current_total_calories > max_calories)
        {
            // std::cout << "new max calories!\n";
            // std::cout << "old max: " << max_calories << "\n";
            // std::cout << "new max: " << current_total_calories << "\n";
            // std::cout << "old elf: " << max_calories_elf << "\n";
            // std::cout << "new elf: " << current_elf << std::endl;
            max_calories = current_total_calories;
            max_calories_elf = current_elf;
            // code smell - repeated code...
            current_elf++;
            current_total_calories = 0;
            continue;
        }
        else if (line == "")
        {
            // std::cout << "no new max" << std::endl;
            current_elf++;
            current_total_calories = 0;
            continue;
        }

        // process elf calories... simply add them up
        // - trim whitespace
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

    std::cout << "max calorie elf is: " << max_calories_elf << "\n";
    std::cout << "max calories is: " << max_calories << "\n";
    std::cout << "total elves: " << current_elf << std::endl;

    return 0;
}