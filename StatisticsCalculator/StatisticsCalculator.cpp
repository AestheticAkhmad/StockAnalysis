//
// Created by Akhmad Oripov  on 20/01/2023.
//

#include "StatisticsCalculator.hpp"

double StatisticsCalculator::GetAverageStockPrice(std::size_t startDate, std::size_t endDate, std::vector<std::shared_ptr<Stock>> &vecStockData) {
    auto vecIter = startDate;
    double sum{};
    for(auto i = vecIter; i <= endDate; ++i) {
        sum += vecStockData[i]->closePrice;
    }
    return sum/static_cast<double>(endDate-startDate);
}

double StatisticsCalculator::GetMedianStockPrice(std::size_t startDate, std::size_t endDate, std::vector<std::shared_ptr<Stock>> &vecStockData) {
    std::vector<double> prices{};
    auto vecIter = startDate;
    for(auto i = vecIter; i <= endDate; ++i) {
        prices.push_back(vecStockData[i]->closePrice);
    }
    std::sort(prices.begin(), prices.end());
    if(prices.size() % 2 == 0) {
        return (prices[prices.size()/2] + prices[prices.size()/2 + 1])/2;
    } else {
        return prices[prices.size()/2];
    }
}
