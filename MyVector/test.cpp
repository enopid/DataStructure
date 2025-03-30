#include "MyVector.cpp"

void TestGeometricGrowth(){
    MyVector<int> myvector = MyVector<int>();
    std::cout << "Vector geometric growth check" <<"\n";
    myvector.Print(false);
    for (size_t i = 0; i < 100; i++)
    {
        myvector.push_back(i);
        if (i%10==0){
            std::cout << "After pushing back " << i <<"\n";
            myvector.Print(false);
        }
    }
    std::cout <<"\n";
}

void TestSizeManipulation(){
    std::cout << "Vector size manipulation check" <<"\n";
    MyVector<int> myvector = MyVector<int>(10,5);
    myvector.Print();
    std::cout << "Resize to 5" <<"\n";
    myvector.resize(5);
    myvector.Print();
    std::cout << "Resize to 10" <<"\n";
    myvector.resize(10);
    myvector.Print();
    std::cout << "Resize to 15 with 3" <<"\n";
    myvector.resize(15,3);
    myvector.Print();
    std::cout << "Reserve to 20" <<"\n";
    myvector.reserve(20);
    myvector.Print();
    std::cout << "fit vector capacity" <<"\n";
    myvector.shrink_to_fit();
    myvector.Print();
    std::cout << "clear" <<"\n";
    myvector.clear();
    myvector.Print();
}

void TestSizeManipulation1(int n){
    std::cout << "Vector linear growth" <<"\n";
    MyVector<int> myvector = MyVector<int>();
    for (size_t i = 0; i < n; i++) myvector.linear_push_back(i);
}

void TestSizeManipulation2(int n){
    std::cout << "Vector exponential growth" <<"\n";
    MyVector<int> myvector = MyVector<int>();
    for (size_t i = 0; i < n; i++) myvector.push_back(i);
}


void TestSizeManipulation3(int n){
    std::cout << "Vector reserve first" <<"\n";
    MyVector<int> myvector = MyVector<int>();
    myvector.reserve(n);
    for (size_t i = 0; i < n; i++) myvector[i]=i;
}