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
#include <vector>
#include "../Stock.hpp"

class StatisticsCalculator {
public:
    double GetAverageStockPrice(std::size_t startDate, std::size_t endDate, std::vector<std::shared_ptr<Stock>> &vecStockData);
    double GetMedianStockPrice(std::size_t startDate, std::size_t endDate, std::vector<std::shared_ptr<Stock>> &vecStockData);
};


#endif //STOCKSTATISTICS_STATISTICSCALCULATOR_HPP
