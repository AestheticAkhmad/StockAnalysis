//
// Created by Akhmad Oripov  on 17/01/2023.
//

#ifndef STOCKSTATISTICS_DATACOLLECTOR_HPP
#define STOCKSTATISTICS_DATACOLLECTOR_HPP

#include "../Stock.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <memory>
#include <sstream>
#include <string>

class DataCollector {
public:
    DataCollector(const std::string stockName, std::map<std::size_t, std::shared_ptr<Stock>> &stockData, std::vector<std::shared_ptr<Stock>> &vecStockData);
};


#endif //STOCKSTATISTICS_DATACOLLECTOR_HPP
