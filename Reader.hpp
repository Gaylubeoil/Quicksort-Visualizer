#pragma once
#include <fstream>
#include <vector>

class Reader
{
public:
    static Reader &getInstance()
    {
        // Guarantees that the instance will be destroyed.
        static Reader instance;
        return instance;
    }

private:
    Reader() {}

public:
    Reader(Reader const &) = delete;
    void operator=(Reader const &) = delete;

    // This function will read data from a specified (/*hardcoded*/) file and save it's content in the passed vector.
    void read_from_file(std::vector<int> &input);
};
