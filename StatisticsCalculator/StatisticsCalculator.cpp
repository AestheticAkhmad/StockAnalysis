//
// Created by Akhmad Oripov  on 20/01/2023.
//

#include "StatisticsCalculator.hpp"

double StatisticsCalculator::GetAverageStockPrice(std::size_t startDate, std::size_t endDate, std::vector<std::shared_ptr<Stock>> &vecStockData) {
    auto vecIter = vecStockData.begin() + startDate;
    double sum{};
    std::cout<<startDate<<" "<<endDate<<"\n";
    for(auto i = vecIter; i < vecStockData.end() - endDate; ++i) {
        sum += (i->get()->closePrice);
        std::cout<<sum<<"\n";
    }
    std::cout<<endDate - startDate<<" "<<sum<<"\n";
    return sum/(endDate-startDate);
}

double StatisticsCalculator::GetMedianStockPrice(std::size_t startDate, std::size_t endDate, std::vector<std::shared_ptr<Stock>> &vecStockData) {
    std::vector<double> prices{};
    auto vecIter = vecStockData.begin() + startDate;
    for(auto i = vecIter; i < vecStockData.end() - endDate; ++i) {
        prices.push_back(i->get()->closePrice);
        std::cout<<i->get()->closePrice<<"\n";
    }
    std::sort(prices.begin(), prices.end());
    std::cout<<"prices size: "<<prices.size()<<"\n";
    if(prices.size() % 2 == 0) {
        return (prices[prices.size()/2] + prices[prices.size()/2 + 1])/2;
    } else {
        return prices[prices.size()/2];
    }
}