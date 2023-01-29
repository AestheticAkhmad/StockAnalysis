//
// Created by Akhmad Oripov  on 21/01/2023.
//

#ifndef STOCKSTATISTICS_ANALYSISINITIALIZER_HPP
#define STOCKSTATISTICS_ANALYSISINITIALIZER_HPP

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <tuple>
#include "../Stock.hpp"
#include "../StatisticsCalculator/StatisticsCalculator.hpp"
#include "../DataCollector/DataCollector.hpp"

struct indexData {
    std::size_t from{};
    std::size_t to{};
    bool exist{};
    indexData(std::size_t from, std::size_t to, bool exist) : from(from), to(to), exist(exist) {}
};

class AnalysisInitializer {
private:
    StatisticsCalculator statsCalc{};
    std::map<std::size_t, std::shared_ptr<Stock>> stockData{};
    std::vector<std::shared_ptr<Stock>> vecStockData{};

    indexData GetIndicesAndValidate(std::size_t from, std::size_t to);
    //double GetStandardDeviationStockInRangeHelper(std::time_t &from, std::time_t &to);
public:
    explicit AnalysisInitializer(const std::string &stockName);
    std::size_t ConvertStrDateToTime(std::string &strDate);
    double GetAverageStockPriceInRange(std::string &from, std::string &to);
//    double GetVarianceStockInRange(std::string &from, std::string &to);
//    double GetStandardDeviationStockInRange(std::string &from, std::string &to);
    double GetMedianStockInRange(std::string &from, std::string &to);
};


#endif //STOCKSTATISTICS_ANALYSISINITIALIZER_HPP
