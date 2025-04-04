#include "TestCases.h"

void TestGeometricGrowth(){
    MyVector<int> myvector = MyVector<int>();
    std::cout << "Vector geometric growth check" <<"\n";
    myvector.print(false);
    for (int i = 0; i < 100; i++)
    {
        myvector.push_back(i);
        if (i%10==0){
            std::cout << "After pushing back " << i <<"\n";
            myvector.print(false);
        }
    }
    std::cout <<"\n";
}

void TestSizeManipulation(){
    std::cout << "Vector size manipulation check" <<"\n";
    MyVector<int> myvector = MyVector<int>(10,5);
    myvector.print();
    std::cout << "Resize to 5" <<"\n";
    myvector.resize(5);
    myvector.print();
    std::cout << "Resize to 10" <<"\n";
    myvector.resize(10);
    myvector.print();
    std::cout << "Resize to 15 with 3" <<"\n";
    myvector.resize(15,3);
    myvector.print();
    std::cout << "Reserve to 20" <<"\n";
    myvector.reserve(20);
    myvector.print();
    std::cout << "fit vector capacity" <<"\n";
    myvector.shrink_to_fit();
    myvector.print();
    std::cout << "clear" <<"\n";
    myvector.clear();
    myvector.print();
}

void TestSizeManipulation1(int n, bool verbose){
    if (verbose) std::cout << "Vector linear growth" <<"\n";
    MyVector<int> myvector;
    for (int i = 0; i < n; i++) myvector.linear_push_back(i);
}

void TestSizeManipulation2(int n, bool verbose){
    if (verbose) std::cout << "Vector exponential growth" <<"\n";
    MyVector<int> myvector;
    for (int i = 0; i < n; i++) myvector.push_back(i);
}


void TestSizeManipulation3(int n, bool verbose){
    if (verbose) std::cout << "Vector reserve first" <<"\n";
    MyVector<int> myvector;
    myvector.reserve(n);
    for (int i = 0; i < n; i++) myvector.push_back(i);
}

void TestSizeManipulation4(int n, bool verbose) {
    if (verbose) std::cout << "Vector exponential growth" << "\n";
    std::vector<int> myvector;
    for (int i = 0; i < n; i++) myvector.push_back(i);
}

void TestSizeManipulation5(int n, bool verbose) {
    if (verbose) std::cout << "Vector reserve first" << "\n";
    std::vector<int> myvector;
    myvector.reserve(n);
    for (int i = 0; i < n; i++) myvector.push_back(i);
}

void TestCapacityCheck1(int n, bool verbose)
{
    if (verbose) std::cout << "Vector capacity check" << "\n";
    std::vector<int> myvector;
    int curCapacity = -1;
    for (int i = 0; i < n; i++) { myvector.push_back(i); 
    if (curCapacity== myvector.capacity()) continue;
    curCapacity = myvector.capacity();
    std::cout << i << "\t" << curCapacity << "\n";
    }
}

void TestCapacityCheck2(int n, bool verbose)
{
    if (verbose) std::cout << "MyVector capacity check" << "\n";
    MyVector<int> myvector;
    int curCapacity = -1;
    for (int i = 0; i < n; i++) {
        myvector.push_back(i);
        if (curCapacity == myvector.capacity()) continue;
        curCapacity = myvector.capacity();
        std::cout << i << "\t" << curCapacity << "\n";
    }
}
