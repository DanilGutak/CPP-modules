#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>

std::string replace(std::string str, std::string word1, std::string word2)
{
    std::string res;

    unsigned long pos1 = 0;
    unsigned long pos2 = 0;

    if (word1 == "")
        return (str);
    while ((pos2 = str.find(word1, pos1)) != std::string::npos)
    {
        res += str.substr(pos1, pos2 - pos1);
        res += word2;
        pos1 = pos2 + word1.length();
    }
    res += str.substr(pos1);
    return (res);
}
int main(int argc, char **argv){
    if (argc != 4)
    {
        std::cout << "Wrong number of arguments\n";
        return (1);
    }
    
    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
        std::cout << "Could not open the file to read\n";
        return (1);
    }
    std::string resfile = (std::string)argv[1] + ".replace";
    std::ofstream output(resfile.c_str());
    if (!output.is_open())
    {
        std::cout << "Could not open the file to write\n";
        input.close();
        return (1);
    }
    std::string line;
    std::string res;
    while (std::getline(input, line))
    {
        res += line;
        if (input.eof())
            break;
        res+="\n";
    }
    output << replace(res,argv[2],argv[3]);
    input.close();
    output.close();

}