#include "test.cpp"
#include <iostream>
#include <chrono>

void MeasureTime(void (*func)(int), int n) {
    auto start = std::chrono::high_resolution_clock::now();
    func(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
}

int main(){
    TestGeometricGrowth();
    TestSizeManipulation();

    int n = 100000;
    MeasureTime(TestSizeManipulation1, n);
    MeasureTime(TestSizeManipulation2, n);
    MeasureTime(TestSizeManipulation3, n);
    return 0;
}