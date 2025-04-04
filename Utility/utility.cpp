#include "utility.h"

double Utility::MeasureTime(void (*func)(int, bool), int n, bool verbose) {
    auto start = std::chrono::high_resolution_clock::now();
    func(n, verbose);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    if (verbose) std::cout << "Elapsed time: " << elapsed.count()*1000 << " miliseconds\n";
    return elapsed.count()*1000;
}

double Utility::MeasureTimeAvg(void(*func)(int, bool), int n, int repeatTime, bool verbose)
{
    //double result(0);
    double result(10000000);
    for (int i=0; i < repeatTime; i++) {
        //result+=MeasureTime(func, n, verbose);
        result=fmin(result, MeasureTime(func, n, verbose));
    }
    //if (verbose) std::cout << "Avg Elapsed time: " << result/repeatTime << " miliseconds\n\n";
    if (verbose) std::cout << "Avg Elapsed time: " << result << " miliseconds\n\n";
    //return result/repeatTime;
    return result;
}

void Utility::benchmarkToFile(void(*func)(int, bool), int step, int iteration, const std::string& filename)
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "파일을 열 수 없습니다: " << filename << "\n";
        return;
    }

    file << "InputSize,Time(ms)\n";  // CSV 헤더

    for (int i = 1; i <= iteration;  i++) {
        double time = MeasureTimeAvg(func, i*step, 10);
        file << i*step << "," << time << "\n";
        std::cout << i*step << "\n";
    }

    file.close();
}
