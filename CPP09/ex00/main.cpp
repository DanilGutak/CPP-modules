
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::map <std::string, double> db;
    if (argc != 2)
    {
        std::cout << "Usage: ./btc \"filename\"\n";
        return 1;
    }
    std::string filename = argv[1];
    try
    {
        db = BitcoinExchange::readdb("data.csv");
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << " in Database\n";
        return 1;
    }
    //print db
    try
    {
        BitcoinExchange::calculate(db, filename);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << " in Input\n";
        return 1;
    }

    return 0;


}