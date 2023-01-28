//
// Created by Akhmad Oripov  on 20/01/2023.
//

#ifndef STOCKSTATISTICS_STATISTICSCALCULATOR_HPP
#define STOCKSTATISTICS_STATISTICSCALCULATOR_HPP

#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include "../Stock.hpp"

class StatisticsCalculator {
public:
    double GetAverageStockPrice(std::time_t startDate, std::time_t endDate, std::map<std::time_t, std::shared_ptr<Stock>> &stockData, std::vector<std::shared_ptr<Stock>> &vecStockData);
};


#endif //STOCKSTATISTICS_STATISTICSCALCULATOR_HPP
