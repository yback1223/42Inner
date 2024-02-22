#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

#define PRICE_DB_PATH ("data.csv")

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: " << BitcoinExchange::FileOpenException().what() << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange exc(PRICE_DB_PATH);

        std::ifstream rate_db(argv[1]);
        if (!rate_db.is_open())
            throw BitcoinExchange::FileOpenException();
        
        exc.factored_price(rate_db, "date | value", " | ");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}