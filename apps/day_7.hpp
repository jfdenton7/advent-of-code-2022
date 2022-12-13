#pragma once
#ifndef __DAY_7_HPP

#include <advent/lib.hpp>

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

const int DAY = 7;
// max size of allowed dir
const int LIMIT_SZ = 100000;

const int DISK_SPACE = 70000000;
const int UPDATE_SZ = 30000000;

enum class CmdType
{
    CD,
    LS
};

struct Cmd
{
    CmdType type;
    std::string move_to;
    std::vector<std::string> out;
};

struct File
{
    std::string name;
    int size;
};


class Dir
{
public:
    std::vector<File> files;
    std::vector<Dir*> dirs;
    Dir* parent;

    std::string name;

    Dir(std::string s, Dir *parent);
    ~Dir();
    int size();
    Dir* find_dir(std::string s);
};

std::vector<Cmd> build_cmd_list(std::vector<std::string> input);
std::vector<int> find_del_options(Dir* dir, std::vector<int> options, int disk_del_goal);
Dir* create_root_dir(std::vector<Cmd> cmd_list);
int find_dir_limit_sum(Dir* dir, int limit);
int min(std::vector<int> v);

#endif // !__DAY_7_HPP
