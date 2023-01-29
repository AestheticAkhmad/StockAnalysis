#include <iostream>
#include "AnalysisInitializer/AnalysisInitializer.hpp"

using namespace std;

int main() {
    string stock = "DataCollector/AMZN.txt";
    string from = "2022-11-11";
    string to = "2022-12-12";
    AnalysisInitializer initStock(stock);
    auto average = initStock.GetAverageStockPriceInRange(from, to);
    auto median = initStock.GetMedianStockInRange(from, to);
    cout<<"Average: "<<average<<" | Median: "<<median<<endl;
    return 0;
}
