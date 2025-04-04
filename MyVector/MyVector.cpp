#include<cstring>
#include<iostream>

template<typename T>
class MyVector{
public:
    MyVector(){
        _size=0;
        _capacity=1;
        _data=new T[_capacity];
    }
    MyVector(int N, const T& val=T()){
        _size=N;
        _capacity=N;
        _data=new T[N];
        for (int i = 0; i < _size; i++) _data[i]=val;
    }
    ~MyVector(){
        delete[] _data;
    }

    //member access
    int size(){return _size;}
    int capacity(){return _capacity;}
    T* data(){return _data;}

    //capacity modification
    void resize(int newsize){
        if (_capacity< newsize){reserve(newsize);}
        for (int i = _size; i < newsize; i++) _data[i]=T();
        _size= newsize;
    }
    void resize(int newsize, const T& val){
        if (_capacity< newsize){reserve(newsize);}
        for (int i = _size; i < newsize; i++) _data[i]=val;
        _size= newsize;
    }
    void clear(){_size=0;}
    bool empty(){return (_size==0);}
    void reserve(int newcapacity){
        if (_capacity < newcapacity) {
            T* newData = new T[newcapacity];
            memcpy(newData, _data, sizeof(T) * _size);
            //for (int i = 0; i < _size; ++i) newData[i] = _data[i];
            delete[] _data;
            _data = newData;
            _capacity = newcapacity;
        }
    }
    void shrink_to_fit(){
        if (_capacity>_size){
            T* _containerPtr=new T[_size];
            memcpy(_containerPtr,_data, sizeof(T)*_size);
            delete[] _data;
            _data=_containerPtr;

            _capacity=_size;
        }
    }
    static void set_growth_factor(double growth_factor) {
        _growthFactor = growth_factor;
    }

    //element manipulation
    void insert(int pos, const T& val){
        if (pos>=_size) return;
        if (_size>=_capacity){reserve(_capacity*2);}
        for (int i = _size; i > pos; i--){_data[i]=_data[i-1];}
        _data[pos]=val;
        _size++;
    }
    void erase(int pos){
        if (pos<0 || pos>=_size) return;
        for (int i = pos; i < _size-1; i++){_data[i]=_data[i+1];}
        _size--;
    }
    void pop_back(){
        if (!empty()){_size--;}
    }
    void push_back(const T& val){
        if (_size >= _capacity) { reserve(std::max(int(_capacity * _growthFactor),2)); }
        _data[_size++]=val;
    }
    void linear_push_back(const T& val){
        if (_size>=_capacity){reserve(_capacity+10);}
        _data[_size++]=val;
    }

    //element access
    T& operator[] (int ind){
        return _data[ind];
    }
    T& front (){
        return _data[0];
    }
    T& back (){
        return _data[_size-1];
    }

    //utility
    void print(bool printElements=true){
        std::cout << "Size : " << _size << " / Capacity : " << _capacity << "\n";
        if (printElements){
            std::cout << "elements : ";
            for (size_t i = 0; i < _size; i++) std::cout << _data[i] << " ";
            std::cout << "\n";
        }
    }
    

private:
    int _size;
    int _capacity;
    static double _growthFactor;
    T *_data;
};

template<typename T>
double MyVector<T>::_growthFactor = 2;

