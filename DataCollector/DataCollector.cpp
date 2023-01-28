//
// Created by Akhmad Oripov  on 17/01/2023.
//

#include "DataCollector.hpp"

DataCollector::DataCollector(const std::string stockName, std::map<std::time_t, std::shared_ptr<Stock>> &stockData, std::vector<std::shared_ptr<Stock>> &vecStockData) {
    std::fstream stockDataStream;
    stockDataStream.open(stockName);
    std::string lineData;
    getline(stockDataStream, lineData);
    size_t index{};
    while(stockDataStream.is_open() && getline(stockDataStream, lineData)) {
        std::stringstream lineDataExtraction(lineData);
        std::string dateStrIn{}, dateStr{};
        double openPrice{}, highPrice{}, lowPrice{}, closePrice{};
        lineDataExtraction>>dateStrIn>>openPrice>>highPrice>>lowPrice>>closePrice;
        std::copy_if(dateStrIn.begin(), dateStrIn.end(), std::back_inserter(dateStr),
                                           [](unsigned char c)
                                           {return std::isdigit(c);});
        std::time_t date = std::stoi(dateStr);
        auto newStock =
                std::make_shared<Stock>(date, openPrice, highPrice, lowPrice, closePrice, index);
        stockData.insert(std::make_pair(date, newStock));
        vecStockData.push_back(newStock);
    }
    stockDataStream.close();
}