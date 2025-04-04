#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <functional>

namespace Utility {
    double MeasureTime(void (*func)(int, bool), int n, bool verbose=false);
    double MeasureTimeAvg(void (*func)(int, bool), int n, int repeatTime, bool verbose = false);
    void benchmarkToFile(void (*func)(int, bool), int step, int iteration, const std::string& filename);
} 