//
// Created by Akhmad Oripov  on 20/01/2023.
//

#include "StatisticsCalculator.hpp"

double StatisticsCalculator::GetAverageStockPrice(std::time_t startDate, std::time_t endDate, std::map<std::time_t, std::shared_ptr<Stock>> &stockData, std::vector<std::shared_ptr<Stock>> &vecStockData) {
    double averageStockPrice{};
    for(auto &i : stockData) {
        auto lowHighAverage = i.second->
        averageStockPrice += i.second->
    }
    return averageStockPrice;
}