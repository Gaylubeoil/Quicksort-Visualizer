#include "Reader.hpp"

void Reader::read_from_file(std::vector<int> &input)
{
    std::ifstream input_file;
    input_file.open("input.txt", std::ios::in);
    if (!input_file.is_open())
    {
        return;
    }

    while (input_file.good())
    {
        int var = 0;
        input_file >> var;
        input.push_back(var);
    }

    input_file.close();
}