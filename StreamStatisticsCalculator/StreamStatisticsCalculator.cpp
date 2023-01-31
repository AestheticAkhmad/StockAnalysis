//
// Created by Akhmad Oripov  on 30/01/2023.
//

#include "StreamStatisticsCalculator.hpp"

void StreamStatisticsCalculator::SetCurrentAveragePrice() {
    if(dataSize > 0) {
        currentAverage = currentSum / static_cast<double>(dataSize);
    } else {
        currentAverage = 0;
    }
}

void StreamStatisticsCalculator::SetCurrentVariancePrice() {
    if(dataSize > 1) {
        currentVariance = differenceSquare / static_cast<double>(dataSize - 1);
    } else {
        currentVariance = 0;
    }
}

void StreamStatisticsCalculator::SetCurrentStandardDeviationPrice() {
    if(dataSize > 1) {
        currentStdDev = sqrt(differenceSquare / static_cast<double>(dataSize - 1));
    } else {
        currentStdDev = 0;
    }
}

void StreamStatisticsCalculator::SetDifferenceSquare() {
    differenceSquare = 0;
    for(auto &i : priceData) {
        differenceSquare += pow(i - currentAverage, 2);
    }
}

double StreamStatisticsCalculator::GetCurrentVariancePrice() {
    SetDifferenceSquare();
    SetCurrentVariancePrice();
    return currentVariance;
}

double StreamStatisticsCalculator::GetCurrentStandardDeviationPrice() {
    SetDifferenceSquare();
    SetCurrentStandardDeviationPrice();
    return currentStdDev;
}

double StreamStatisticsCalculator::GetCurrentAveragePrice() const {
    return currentAverage;
}

double StreamStatisticsCalculator::GetCurrentMedianPrice() const {
    if(minQ.empty() && maxQ.empty()) {
        return std::numeric_limits<double>::infinity();
    } else if(minQ.empty() && !maxQ.empty()) {
        return maxQ.top();
    } else if(!minQ.empty() && maxQ.empty()) {
        return minQ.top();
    }

    if(minQ.size() > maxQ.size()) {
        return minQ.top();
    } else if(minQ.size() < maxQ.size()) {
        return maxQ.top();
    }

    double result = (minQ.top() + maxQ.top())/2;
    return result;
}

void StreamStatisticsCalculator::BalanceQueues() {
    auto a = static_cast<int>(minQ.size());
    auto b = static_cast<int>(maxQ.size());
    if(abs(a - b) > 1) {
        if(minQ.size() > maxQ.size()) {
            auto k = minQ.top();
            minQ.pop();
            maxQ.push(k);
        } else {
            auto k = maxQ.top();
            maxQ.pop();
            minQ.push(k);
        }
    }
}

void StreamStatisticsCalculator::AppendPrice(double price) {
    priceData.push_back(price);
    currentSum += price;
    dataSize = priceData.size();
    SetCurrentAveragePrice();

    if(maxQ.empty()) {
        maxQ.push(price);
        return;
    }
    auto median =  GetCurrentMedianPrice();
    if(price < median) {
        maxQ.push(price);
    } else {
        minQ.push(price);
    }
    BalanceQueues();
}
