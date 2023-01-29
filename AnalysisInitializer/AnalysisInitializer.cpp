//
// Created by Akhmad Oripov  on 21/01/2023.
//

#include "AnalysisInitializer.hpp"



AnalysisInitializer::AnalysisInitializer(const std::string &stockName) {
    DataCollector dataCollector(stockName, stockData, vecStockData);
    StatisticsCalculator statisticsCalculator;
    statsCalc = statisticsCalculator;
    for(auto i : vecStockData) {
        //std::cout<<i->closePrice<<"\n";
    }
}

std::size_t AnalysisInitializer::ConvertStrDateToTime(std::string &strDate) {
    std::string resultDate{};
    std::copy_if(strDate.begin(), strDate.end(), std::back_inserter(resultDate),
                 [](unsigned char c)
                 {return std::isdigit(c);});
    std::size_t date = std::stoi(resultDate);
    return date;
}

indexData AnalysisInitializer::GetIndicesAndValidate(std::size_t from, std::size_t to) {
    auto fromIter = stockData.find(from);
    auto toIter = stockData.find(to);
    if(fromIter == stockData.end() || toIter == stockData.end()) {
        return {0, 0, false};
    }
    return {fromIter->second.get()->idx, toIter->second.get()->idx, true};
}

double AnalysisInitializer::GetAverageStockPriceInRange(std::string &strFrom, std::string &strTo) {
    auto dateFrom{ConvertStrDateToTime(strFrom)}, dateTo{ConvertStrDateToTime(strTo)};
    auto indices{GetIndicesAndValidate(dateFrom, dateTo)};
    if(!indices.exist) {
        return -1;
    }
    return statsCalc.GetAverageStockPrice(indices.from, indices.to, vecStockData);
}

double AnalysisInitializer::GetMedianStockInRange(std::string &strFrom, std::string &strTo) {
    auto dateFrom{ConvertStrDateToTime(strFrom)}, dateTo{ConvertStrDateToTime(strTo)};
    auto indices{GetIndicesAndValidate(dateFrom, dateTo)};
    if(!indices.exist) {
        return -1;
    }
    return statsCalc.GetMedianStockPrice(indices.from, indices.to, vecStockData);
}