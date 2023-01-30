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
    std::deque<double> priceData{};
    std::size_t dataSize{};
    double currentSum{};

    double GetCurrentSum() const;
public:
    [[nodiscard]] double GetCurrentAveragePrice() const;
    [[nodiscard]] double GetCurrentMedianPrice() const;
    [[nodiscard]] double GetCurrentStandardDeviationPrce() const;
    [[nodiscard]] double GetCurrentVariancePrice() const;
    void AppendPrice(double price);
    void PopFrontPrice();
};


#endif //STOCKSTATISTICS_STREAMSTATISTICSCALCULATOR_HPP
