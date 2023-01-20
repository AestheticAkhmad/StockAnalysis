//
// Created by Akhmad Oripov  on 19/01/2023.
//

#ifndef STOCKSTATISTICS_STOCK_HPP
#define STOCKSTATISTICS_STOCK_HPP

#include <ctime>

class Stock {
public:
    std::time_t date{};
    double openPrice{};
    double highPrice{};
    double lowPrice{};
    double closePrice{};
    Stock(std::time_t date, double openPrice, double highPrice,
          double lowPrice, double closePrice) : date(date), openPrice(openPrice),
          highPrice(highPrice), lowPrice(lowPrice), closePrice(closePrice) {}
};


#endif //STOCKSTATISTICS_STOCK_HPP
