#include "test.cpp"
#include "../Utility/utility.h"
#include <iostream>




int main(){
    TestGeometricGrowth();
    TestSizeManipulation();

    int n = 100000;
    Utility::MeasureTime(TestSizeManipulation1, n);
    Utility::MeasureTime(TestSizeManipulation2, n);
    Utility::MeasureTime(TestSizeManipulation3, n);
    return 0;
}