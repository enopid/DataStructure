#pragma once

#include <chrono>
#include <iostream>

namespace Utility {
    void MeasureTime(void (*func)(int), int n);
} 