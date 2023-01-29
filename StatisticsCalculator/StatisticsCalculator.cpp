//
// Created by Akhmad Oripov  on 20/01/2023.
//

#include "StatisticsCalculator.hpp"

double StatisticsCalculator::GetAverageStockPrice(std::size_t startDate, std::size_t endDate, std::vector<std::shared_ptr<Stock>> &vecStockData) {
    auto vecIter = startDate;
    double sum{};
    auto n = endDate-startDate + 1;
    for(auto i = vecIter; i <= endDate; ++i) {
        sum += vecStockData[i]->closePrice;
    }
    return sum/static_cast<double>(n);
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

double StatisticsCalculator::GetStandardDeviationPrice(std::size_t startDate, std::size_t endDate,
                                                       std::vector<std::shared_ptr<Stock>> &vecStockData) {
    auto average{GetAverageStockPrice(startDate, endDate, vecStockData)}, stdDev{0.0};
    auto n = endDate - startDate + 1;
    for(auto i = startDate; i <= endDate; ++i) {
        stdDev += (pow(vecStockData[i]->closePrice - average, 2));
    }
    return sqrt(stdDev/static_cast<double>(n - 1));
}

double StatisticsCalculator::GetVariancePrice(std::size_t startDate, std::size_t endDate,
                                              std::vector<std::shared_ptr<Stock>> &vecStockData) {
    return pow(GetStandardDeviationPrice(startDate, endDate, vecStockData), 2);
}