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
    void resize(int _size){
        if (_capacity<_size){reserve(_size);}
        for (int i = _size; i < _size; i++) _data[i]=T();
        _size=_size;
    }
    void resize(int _size, const T& val){
        if (_capacity<_size){reserve(_size);}
        for (int i = _size; i < _size; i++) _data[i]=val;
        _size=_size;
    }
    void clear(){_size=0;}
    bool empty(){return (_size==0);}
    void reserve(int _capactiy){
        if (_capacity<_capactiy){
            T* _containerPtr=new T[_capactiy];
            memcpy(_containerPtr,_data, sizeof(T)*_capacity);
            delete[] _data;
            _data=_containerPtr;

            _capacity=_capactiy;
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
        if (_size>=_capacity){reserve(_capacity*2);}
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
    void Print(bool printElements=true){
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
    T *_data;
};

