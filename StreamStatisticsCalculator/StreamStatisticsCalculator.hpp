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
    void SetCurrentAveragePrice();
    void SetCurrentStandardDeviationPrice();
    void SetCurrentVariancePrice();
    void SetDifferenceSquare();
private:
    std::deque<double> priceData{};
    std::size_t dataSize{};
    double currentSum{};
    double currentAverage{};
    double currentStdDev{};
    double currentVariance{};
    double differenceSquare{};
public:
    [[nodiscard]] double GetCurrentAveragePrice() const;
    [[nodiscard]] double GetCurrentMedianPrice() const;
    [[nodiscard]] double GetCurrentStandardDeviationPrice();
    [[nodiscard]] double GetCurrentVariancePrice();
    void AppendPrice(double price);
};


#endif //STOCKSTATISTICS_STREAMSTATISTICSCALCULATOR_HPP
