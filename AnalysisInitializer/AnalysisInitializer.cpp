//
// Created by Akhmad Oripov  on 21/01/2023.
//

#include "AnalysisInitializer.hpp"

std::time_t AnalysisInitializer::ConvertStrDateToTime(std::string &strDate) {
    std::string resultDate{};
    std::copy_if(strDate.begin(), strDate.end(), std::back_inserter(resultDate),
                 [](unsigned char c)
                 {return std::isdigit(c);});
    std::time_t date = std::stoi(resultDate);
    return date;
}

double AnalysisInitializer::GetAverageStockPriceInRange(std::string &strFrom, std::string &strTo) {
    auto dateFrom{ConvertStrDateToTime(strFrom)}, dateTo{ConvertStrDateToTime(strFrom)};
    return
}