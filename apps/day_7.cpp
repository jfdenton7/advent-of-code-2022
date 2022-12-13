#include <day_7.hpp>

int main()
{
    std::fstream fs;
    auto file_name = startup(DAY);
    auto file_opened = open_file(file_name, fs);
    if (file_opened)
    {
        std::vector<std::string> input = parse_problem_input(fs);
        fs.close();
        std::vector<Cmd> cmd_list = build_cmd_list(input);
        Dir* root = create_root_dir(cmd_list);
        std::cout << "Total sum of dirs that hit limit: " << find_dir_limit_sum(root, LIMIT_SZ)  << "\n";
        int disk_del_goal = root->size() - (DISK_SPACE - UPDATE_SZ);
        auto options = find_del_options(root, std::vector<int>{}, disk_del_goal);

        std::cout << "Best Option: " << min(options) << std::endl;
    }
    else
    {
        std::cout << "failed to open file" << std::endl;
        return -1;
    }
    return 0;
}


std::vector<int> find_del_options(Dir* dir, std::vector<int> options, int disk_del_goal)
{
    int size = dir->size();
    if (size >= disk_del_goal)
    {
        options.push_back(size);
    }
    for (Dir* d : dir->dirs)
    {
     options = find_del_options(d, options, disk_del_goal);
    }
    return options;
}

int find_dir_limit_sum(Dir* dir, int limit)
{
    int size = 0;
    for (Dir* d : dir->dirs)
    {
        size += find_dir_limit_sum(d, limit);
    }

    for (Dir* d : dir->dirs)
    {
        int d_size = d->size();
        if (d_size <= limit)
        {
            size += d_size;
        }
    }

    return size;
}

int min(std::vector<int> v)
{
    int min = v.front();
    for (int n : v)
    {
        if (n < min)
        {
            min = n;
        }
    }
    return min;
}

std::vector<Cmd> build_cmd_list(std::vector<std::string> input)
{
    const int CD_OFFSET = 5;
    std::vector<Cmd> cmd_list;
    for (int i = 0; i < input.size(); i++)
    {
        Cmd cmd;
        bool is_cd = input[i].find("$ cd") == 0;
        bool is_ls = input[i].find("$ ls") == 0;
        if (is_cd)
        {
            cmd.type = CmdType::CD;
            cmd.move_to = input[i].substr(CD_OFFSET);
            cmd_list.push_back(cmd);
        }
        else if (is_ls)
        {
            cmd.type = CmdType::LS;
            std::vector<std::string> out;
            int j = i + 1;
            for (; j < input.size(); j++)
            {
                if (input[j].find("$") == 0)
                {
                    break;
                }
                out.push_back(input[j]);
            }
            cmd.out = out;
            cmd_list.push_back(cmd);
            i += j - i - 1;
        }
    }
    return cmd_list;
}

Dir* create_root_dir(std::vector<Cmd> cmd_list)
{
    const int OFFSET = 4;
    Dir* root = new Dir("/", nullptr);
    Dir* dir = root;

    for (Cmd cmd : cmd_list)
    {
        if (cmd.type == CmdType::CD)
        {
            dir = dir->find_dir(cmd.move_to);
        }
        else if (cmd.type == CmdType::LS)
        {
            for (std::string file_obj : cmd.out)
            {
                if (file_obj.find("dir ") == 0)
                {
                    dir->dirs.push_back(new Dir(file_obj.substr(file_obj.find(' ') + 1), dir));
                }
                else
                {
                    File f;
                    f.size = std::stoi(file_obj.substr(0, file_obj.find(' ')));
                    f.name = file_obj.substr(file_obj.find(' ') + 1);
                    dir->files.push_back(f);
                }
            }
        }
    }
    return root;
}

Dir::Dir(std::string name, Dir* parent)
{
    this->parent = parent;
    this->name = name;

    this->dirs = std::vector<Dir*>{};
    this->files = std::vector<File>{};
}

Dir::~Dir()
{
}

int Dir::size()
{
    int size = 0;
    for (Dir* d : this->dirs)
    {
        size += d->size();
    }

    for (File f : this->files)
    {
        size += f.size;
    }

    return size;
}

Dir* Dir::find_dir(std::string s)
{
    if (s == "/")
    {
        return this;
    }
    if (this->parent && s == "..")
    {
        return this->parent;
    }
    for (Dir* d : this->dirs)
    {
        if (s == d->name)
        {
            return d;
        }
    }
    std::cout << "FAILED TO FIND\n";
    return nullptr;
}
