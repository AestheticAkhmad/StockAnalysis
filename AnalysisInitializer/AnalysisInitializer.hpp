//
// Created by Akhmad Oripov  on 21/01/2023.
//

#ifndef STOCKSTATISTICS_ANALYSISINITIALIZER_HPP
#define STOCKSTATISTICS_ANALYSISINITIALIZER_HPP

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "../Stock.hpp"
#include "../StatisticsCalculator/StatisticsCalculator.hpp"
#include "../DataCollector/DataCollector.hpp"

class AnalysisInitializer {
private:
    std::map<std::time_t, std::shared_ptr<Stock>> stockData{};
    std::vector<std::shared_ptr<Stock>> vecStockData{};
    double GetStandardDeviationStockInRangeHelper(std::time_t &from, std::time_t &to);
public:
    AnalysisInitializer(const std::string &stockName);
    std::time_t ConvertStrDateToTime(std::string &strDate);
    double GetAverageStockPriceInRange(std::string &from, std::string &to);
    double GetVarianceStockInRange(std::string &from, std::string &to);
    double GetStandardDeviationStockInRange(std::string &from, std::string &to);
    double GetMedianStockInRange(std::string &from, std::string &to);
};


#endif //STOCKSTATISTICS_ANALYSISINITIALIZER_HPP
