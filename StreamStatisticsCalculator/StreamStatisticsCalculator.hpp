//
// Created by Akhmad Oripov  on 30/01/2023.
//

#ifndef STOCKSTATISTICS_STREAMSTATISTICSCALCULATOR_HPP
#define STOCKSTATISTICS_STREAMSTATISTICSCALCULATOR_HPP

#include <iostream>
#include <queue>
#include <memory>
#include <cmath>
#include <numeric>

class StreamStatisticsCalculator {
private:
    //Data Structures are used for finding median in Data Stream
    std::priority_queue<double, std::vector<double>, std::greater<>> minQ{};
    std::priority_queue<double> maxQ{};
    void BalanceQueues();
private:
    std::deque<double> priceData{};
    std::size_t dataSize{};
    double currentSum{};

public:
    [[nodiscard]] double GetCurrentAveragePrice() const;
    [[nodiscard]] double GetCurrentMedianPrice() const;
//    [[nodiscard]] double GetCurrentStandardDeviationPrice() const;
//    [[nodiscard]] double GetCurrentVariancePrice() const;
    void AppendPrice(double price);
//    void PopFrontPrice();
};


#endif //STOCKSTATISTICS_STREAMSTATISTICSCALCULATOR_HPP
