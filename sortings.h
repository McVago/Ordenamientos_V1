#ifndef SORTINGS_H
#define SORTINGS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
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

// Start of Bubble double / Shaker sort
void shakersort(Array<int> &arr, int end)
{
    bool permutation;
    int en_cours = 0, sens = 1;
    int debut = 1;
    do
    {
        permutation = false;
        while (((sens == 1) && (en_cours < end)) || ((sens == -1) && (en_cours > debut)))
        {
            en_cours += sens;
            if (arr[en_cours] < arr[en_cours-1])
            {
                int temp = arr[en_cours];
                arr[en_cours] = arr[en_cours-1];
                arr[en_cours-1] = temp;
                permutation = true;
            }
        }
        if (sens==1) end--; else debut++;
        sens = -sens;
    }
    while (permutation);
}

#endif // SORTINGS_H
