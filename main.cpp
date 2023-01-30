#include <iostream>
#include "AnalysisInitializer/AnalysisInitializer.hpp"
#include "StreamStatisticsCalculator/StreamStatisticsCalculator.hpp"
#include <string>

int main(int argc, char **argv) {
    std::string stock = "DataCollector/AMZN.txt";
    std::string from = "1997-05-15";
    std::string to = "2023-01-13";
    AnalysisInitializer initStock(stock);
    auto average = initStock.GetAverageStockPriceInRange(from, to);
    auto median = initStock.GetMedianStockInRange(from, to);
    auto stdDev = initStock.GetStandardDeviationStockInRange(from, to);
    auto variance = initStock.GetVarianceStockInRange(from, to);
    std::cout<<"Average: "<<average<<" | Median: "<<median<<std::endl;
    std::cout<<"Standard Dev: "<<stdDev<<" | Variance: "<<variance<<std::endl;

    StreamStatisticsCalculator streamCalc;
    for(auto i = 0; i < 10; ++i) {
        int n{};
        std::cin>>n;
        streamCalc.AppendPrice(n);
        std::cout<<"Average: "<<streamCalc.GetCurrentAveragePrice()<<"\n";
        std::cout<<"Median: "<<streamCalc.GetCurrentMedianPrice()<<"\n";
    }

    return 0;
}
