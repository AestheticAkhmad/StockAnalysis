//
// Created by Akhmad Oripov  on 30/01/2023.
//

#include "StreamStatisticsCalculator.hpp"

double StreamStatisticsCalculator::GetCurrentAveragePrice() const {
    if(dataSize > 0) {
        return currentSum / static_cast<double>(dataSize);
    } else {
        return 0;
    }
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
    ++dataSize;
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