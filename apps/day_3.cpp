#include <day_3.hpp>


int main() {
    std::fstream fs;
    auto file_name = startup(DAY);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        Storage* storage = new Storage(fs);
        std::cout << "total priority: " << storage->storage_priority << "\n";
        std::cout << "total group's priority: " << storage->total_badge_priority << std::endl;
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
    this->rucksack = sack;
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
            auto ip = item_priority(item);
            this->priority_sum += item_priority(item);

        }
    }

    return this->priority_sum;
}

std::set<char> Rucksack::get_unique()
{
    std::set<char> set;
    for (char item : this->rucksack) {
        set.insert(item);
    }
    return set;
}

Storage::Storage(std::fstream &fs)
{
    this->storage_priority = 0;
    this->total_badge_priority = 0;

    std::string rucksack;
    std::vector<Rucksack*> group;
    int group_assign = 1;
    while (std::getline(fs, rucksack))
    {
        Rucksack* rs = new Rucksack(rucksack);
        group.push_back(rs);
        this->storage_priority += rs->priority();
        if (group_assign % 3 == 0) {
            // put rucksacks to badge group and get badge item
            BadgeGroup* bg = new BadgeGroup(group);
            char item = bg->get_badge_item();
            this->total_badge_priority += item_priority(item);
            delete bg;
            // clear group
            group.clear();
        }
        ++group_assign;
    }
}

BadgeGroup::BadgeGroup(std::vector<Rucksack*> group)
{
    this->group = group;
}

BadgeGroup::~BadgeGroup()
{
    for (Rucksack* rs : this->group)
    {
        delete rs;
    }
}

// assume the badge group has all items
char BadgeGroup::get_badge_item()
{

    // create a set out of each rucksack
    std::set<char> r1 = this->group[0]->get_unique();
    std::set<char> r2 = this->group[1]->get_unique();
    std::set<char> r3 = this->group[2]->get_unique();

    // merge all sets, r3 should contain badge item!
    r1.merge(r2); // r2 now contains all dupes from r1 U r2
    r2.merge(r3); // r3 now contains r3 U r2 where r2 is r1 U r2
    
    if (r3.size() == 1) {
        std::cout << "group item: " << *r3.begin() << "\n";
        return *r3.begin();
    }
    throw new std::runtime_error("unable to find group badge!");
    return 0;
}

int item_priority(char item)
{
     if (std::islower(item))
    {
        return (item - LOWER_OFF);
    }
    return (item - UPPER_OFF) + 26;
}
