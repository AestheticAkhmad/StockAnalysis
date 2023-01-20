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

class AnalysisInitializer {
private:
    std::map<std::time_t, std::shared_ptr<Stock>> stockData{};
public:
    AnalysisInitializer();
    std::time_t ConvertStrDateToTime(std::string &strDate);
    double GetAverageStockPriceInRange(std::string &from, std::string &to);
};


#endif //STOCKSTATISTICS_ANALYSISINITIALIZER_HPP
