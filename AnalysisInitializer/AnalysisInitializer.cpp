//
// Created by Akhmad Oripov  on 21/01/2023.
//

#include "AnalysisInitializer.hpp"



AnalysisInitializer::AnalysisInitializer(const std::string &stockName) {
    DataCollector dataCollector(stockName, stockData, vecStockData);
    StatisticsCalculator statisticsCalculator;
    statsCalc = statisticsCalculator;
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
    return {fromIter->second->idx, toIter->second->idx, true};
}

double AnalysisInitializer::GetAverageStockPriceInRange(std::string &strFrom, std::string &strTo) {
    auto dateFrom{ConvertStrDateToTime(strFrom)}, dateTo{ConvertStrDateToTime(strTo)};
    auto indices{GetIndicesAndValidate(dateFrom, dateTo)};
    if(!indices.exist) {
        return -1;
    }
    return StatisticsCalculator::GetAverageStockPrice(indices.from, indices.to, vecStockData);
}

double AnalysisInitializer::GetMedianStockInRange(std::string &strFrom, std::string &strTo) {
    auto dateFrom{ConvertStrDateToTime(strFrom)}, dateTo{ConvertStrDateToTime(strTo)};
    auto indices{GetIndicesAndValidate(dateFrom, dateTo)};
    if(!indices.exist) {
        return -1;
    }
    return StatisticsCalculator::GetMedianStockPrice(indices.from, indices.to, vecStockData);
}

double AnalysisInitializer::GetStandardDeviationStockInRange(std::string &strFrom, std::string &strTo) {
    auto dateFrom{ConvertStrDateToTime(strFrom)}, dateTo{ConvertStrDateToTime(strTo)};
    auto indices{GetIndicesAndValidate(dateFrom, dateTo)};
    if(!indices.exist) {
        return -1;
    }
    return StatisticsCalculator::GetStandardDeviationPrice(indices.from, indices.to, vecStockData);
}

double AnalysisInitializer::GetVarianceStockInRange(std::string &strFrom, std::string &strTo) {
    auto dateFrom{ConvertStrDateToTime(strFrom)}, dateTo{ConvertStrDateToTime(strTo)};
    auto indices{GetIndicesAndValidate(dateFrom, dateTo)};
    if(!indices.exist) {
        return -1;
    }
    return StatisticsCalculator::GetVariancePrice(indices.from, indices.to, vecStockData);
}