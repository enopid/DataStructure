#include "TestCases.h"
#include "utility.h"
#include <iostream>
#include <vector>
int main(){
    int step = 1000;
    int iteration = 100;

    //check well function
    TestGeometricGrowth();
    TestSizeManipulation();

    //check special case for comparsion
    //Utility::benchmarkToFile(TestSizeManipulation1, step, iteration, "LinearCase.csv");
    //Utility::benchmarkToFile(TestSizeManipulation3, step, iteration, "ReserveFirstCase.csv");

    //
    MyVector<int>::set_growth_factor(1.5);
    Utility::benchmarkToFile(TestSizeManipulation2, step, iteration, "ExpCase_1_5.csv");

    MyVector<int>::set_growth_factor(1.5);
    Utility::benchmarkToFile(TestSizeManipulation2, step, iteration, "ExpCase_1_5.csv");
    MyVector<int>::set_growth_factor(2);
    Utility::benchmarkToFile(TestSizeManipulation2, step, iteration, "ExpCase_2.csv");
    MyVector<int>::set_growth_factor(3);
    Utility::benchmarkToFile(TestSizeManipulation2, step, iteration, "ExpCase_3.csv");
    MyVector<int>::set_growth_factor(4);
    Utility::benchmarkToFile(TestSizeManipulation2, step, iteration, "ExpCase_4.csv");
    MyVector<int>::set_growth_factor(5);
    Utility::benchmarkToFile(TestSizeManipulation2, step, iteration, "ExpCase_5.csv");

    //compare with stl::vector library
    Utility::benchmarkToFile(TestSizeManipulation4, step, iteration, "vecExpCase.csv");
    Utility::benchmarkToFile(TestSizeManipulation5, step, iteration, "vecReserveFirstCase.csv");
    TestCapacityCheck1(step*iteration, true);
    MyVector<int>::set_growth_factor(1.5);
    TestCapacityCheck2(step * iteration, true);

    return 0;
}