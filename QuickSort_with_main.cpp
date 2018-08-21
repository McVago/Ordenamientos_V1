#include <iostream>
#include <cstdlib>
#include <ctime>

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

//Start of quicksort

//function to make partitions
int partition(Array<int> arr, int low, int high){
  int temp;
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= (high - 1); j++){
    if (arr[j] <= pivot){ //changes acording to which one is higher
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return (i + 1);
}

//final quicksort
void quicksort(Array<int> arr, int low, int high){
  if (low < high){
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);//Makes a new group with the highers
    quicksort(arr, pi + 1, high);//Makes a new group with the lowers

  }
}


int main(){
  int i,c,l;
  srand((unsigned)time(0));
  c = 0;
  std::cout << "Ingrese la cantidad de elementos de la lista :" << std::endl;
  std::cin >> i;
  if (i == 0)
    i = 1;
  Array<int> A((i - 1), c);
  for (int j = 0; j <= (i-1); j++){
    c = (rand()%1000)+1;
    A[j] = c;
    //std::cout << "Me cago en Dios" << c << std::endl;
  }
  //for (int j = 0; j <= (i-1); j++) std::cout << A[j] << std::endl;
  quicksort(A, 0, i);
  std::cout << "[";
  for (int j = 0; j <= (i-1); j++) std::cout << A[j] <<",";
  std::cout << "]"<< std::endl;
  std::cout << "Listo" << std::endl;
  std::cin >> l;
}
