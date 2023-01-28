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
    size_t idx{};
    Stock(std::time_t date, double openPrice, double highPrice,
          double lowPrice, double closePrice, size_t idx) : date(date), openPrice(openPrice),
          highPrice(highPrice), lowPrice(lowPrice), closePrice(closePrice), idx(idx) {}
};


#endif //STOCKSTATISTICS_STOCK_HPP
