#include <day_3.hpp>

int match_count = 0;

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
    this->priority_sum = 0;
}

int Rucksack::priority()
{
    std::string &comp_1 = this->compartments.front();
    std::string &comp_2 = this->compartments.back();

    std::set<char> set_1;
    std::set<char> set_2;

    for (char item : comp_1)
    {
        set_1.insert(item);
    }

    for (char item : comp_2)
    {
        set_2.insert(item);
    }

    for (char item : set_1)
    {
        if (set_2.count(item))
        {
            auto ip = this->item_priority(item);
            std::cout << "for item: " << item << "prio: " << ip << "\n";
            this->priority_sum += this->item_priority(item);

        }
    }

    return this->priority_sum;
}

int Rucksack::item_priority(char item)
{
    if (std::islower(item))
    {
        return (item - this->LOWER_OFF);
    }
    return (item - this->UPPER_OFF) + 26;
}

Storage::Storage(std::fstream &fs)
{
    this->storage_priority = 0;
    std::string rucksack;
    int i = 1;
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
