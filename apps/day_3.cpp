#include <day_3.hpp>

int main() {
    std::fstream fs;
    auto file_name = startup(3);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        Storage* storage = new Storage(fs);
        std::cout << "total priority: " << storage->storage_priority << std::endl;
        delete storage;
    }
    else
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}

Rucksack::Rucksack(std::string &sack)
{
    // guaranteed the string length to be even
    std::string comp_1 = sack.substr(0, sack.size() / 2);
    std::string comp_2 = sack.substr(sack.size() / 2, sack.size() - (sack.size() / 2));
    this->compartments = std::vector{comp_1, comp_2};
}

int Rucksack::priority()
{
    // build the set (change to map if necessary)..
    std::string &comp_1 = this->compartments.front();
    std::string &comp_2 = this->compartments.back();

    std::set<char> set;
    
    for (char item : comp_1)
    {
        set.insert(item);
    }

    for (char item : comp_2)
    {
        if (set.count(item))
        {
            this->priority_sum += this->item_priority(item);
        }
    }

    return 0;
}

int Rucksack::item_priority(char item)
{
    if (std::islower(item))
    {
        return item - this->LOWER_OFF;
    }
    return item - this->UPPER_OFF;
}

Storage::Storage(std::fstream &fs)
{
    this->storage_priority = 0;
    std::string rucksack;
    while (std::getline(fs, rucksack))
    {
        Rucksack* rs = new Rucksack(rucksack);
        this->rucksacks.push_back(rs);
        this->storage_priority += rs->priority();
    }
}

Storage::~Storage()
{
    for (Rucksack* rs : this->rucksacks)
    {
        delete rs;
    }
}
