#include <iostream>
#include "AnalysisInitializer/AnalysisInitializer.hpp"

using namespace std;

int main() {
    string stock = "DataCollector/AMZN.txt";
    string from = "2023-01-03";
    string to = "2023-01-13";
    AnalysisInitializer initStock(stock);
    auto average = initStock.GetAverageStockPriceInRange(from, to);
    auto median = initStock.GetMedianStockInRange(from, to);
    auto stdDev = initStock.GetStandardDeviationStockInRange(from, to);
    auto variance = initStock.GetVarianceStockInRange(from, to);
    cout<<"Average: "<<average<<" | Median: "<<median<<endl;
    cout<<"Standard Dev: "<<stdDev<<" | Variance: "<<variance<<endl;
    return 0;
}
