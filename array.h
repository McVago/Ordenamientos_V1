#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


template <class T>
class Array
{
private:
    int n;
    T* pelement;

public:
    Array(int, T);
    void operator = (T x);
    T& operator [] (int);
};

template <class T>
Array<T>::Array(int a, T init_value)
    :n{a},pelement{new T{a}}{
    for (int i = 0; i < a; i++){
        pelement[i]=init_value;
    }
}

template <class T>
void Array<T>::operator =(T v){
    for (int i = 0; i < n; i++) pelement[i] = v;
}

template <class T>
T& Array<T>::operator [](int i){
    return pelement[i];
}


#endif // ARRAY_H
