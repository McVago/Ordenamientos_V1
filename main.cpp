#include <iostream>
#include <cstdlib>
#include <ctime>
#include "array.h"
#include "sortings.h"
#include "mainwindow.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    int i,c,l;
    srand((unsigned)time(0));
    c = 0;
    cout << "Ingrese la cantidad de elementos de la lista :" << endl;
    i = 5;
    //cin >> i;
    if (i == 0)
    i = 1;
    Array<int> A((i - 1), c);
    for (int j = 0; j <= (i-1); j++)
    {
        c = (rand()%1000)+1;
        A[j] = c;
    }
    cout << "[";
    for (int j = 0; j <= (i-1); j++) cout << A[j] << ",";
    cout << "]"<< endl;
    //quicksort(A, 0, (i-1));
    //shakersort(A,i);
    //shellSort(A,i);
    //insertionSort(A,i);
    //mergeSort(A,0,(i - 1));
    cout << "[";
    for (int j = 0; j <= (i - 1); j++) cout << A[j] <<",";
    cout << "]"<< endl;
    cout << "Listo" << endl;
    return 0;
    //cin >> l;
    //return a.exec();
}
