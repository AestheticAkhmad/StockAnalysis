cmake_minimum_required(VERSION 3.21)
project(StockStatistics)
#add_subdirectory(Google_tests/googletest-main)
set(CMAKE_CXX_STANDARD 23)


file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/DataCollector)

add_executable(StockStatistics main.cpp DataCollector/DataCollector.cpp DataCollector/DataCollector.hpp Stock.hpp StatisticsCalculator/StatisticsCalculator.cpp StatisticsCalculator/StatisticsCalculator.hpp AnalysisInitializer/AnalysisInitializer.cpp AnalysisInitializer/AnalysisInitializer.hpp)

add_custom_command(TARGET StockStatistics PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/DataCollector/AMZN.txt
        ${CMAKE_CURRENT_BINARY_DIR}/DataCollector/AMZN.txt)