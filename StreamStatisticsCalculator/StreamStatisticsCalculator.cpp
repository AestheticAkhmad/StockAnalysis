//
// Created by Akhmad Oripov  on 30/01/2023.
//

#include "StreamStatisticsCalculator.hpp"

double StreamStatisticsCalculator::GetCurrentSum() const {
    return std::accumulate(priceData.begin(), priceData.end(), 0.0);
}

double StreamStatisticsCalculator::GetCurrentAveragePrice() const {

}