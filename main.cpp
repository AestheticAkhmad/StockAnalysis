#include <iostream>
#include "DataCollector/DataCollector.hpp"

using namespace std;

int main() {
    string stock = "DataCollector/AMZN.txt";
    DataCollector collectData(stock);
    collectData.PrintAnyStock();
    return 0;
}
