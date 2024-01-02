#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv){
    if (argc != 4)
    {
        std::cout << "Wrong number of arguments\n";
        return (0);
    }
    
    std::ifstream outputFile(argv[1]);
    std::string resfile = (std::string)argv[1] + ".replace";
    std::ofstream outputFile1(resfile.c_str());
}