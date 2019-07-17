#ifndef __QUICKSORT_H_
#define __QUICKSORT_H_

#include <iostream>
#include <vector>
#include <string>
using namespace std;


namespace Quicksort {
template<typename T>   
int partition(T numbers[], int i, int k) {
    int l = 0;
    int h = 0;
    int midpoint = 0;
    T pivot;
    T temp;
    bool done = false;
    midpoint = i + (k - i)/2;
    pivot = numbers[midpoint];
    l = i;
    h = k;
    while (!done) {
        while (numbers[l] < pivot) {
            l++;
        }
        while (pivot < numbers[h]) {
            h--;
        }
        if (l >=h) {
            done = true;
        }
        else {
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;
            l++;
            h--;
        }
    }
    return h;
}
template<typename T>
int partition(vector<T> &v, int i, int k) {
    int l = 0;
    int h = 0;
    int midpoint = 0;
    T pivot;
    T temp;
    bool done = false;
    midpoint = i + ((k - i)/2);
    pivot = v.at(midpoint);
    l = i;
    h = k;
    while (!done) {
        while (v.at(l) < pivot) {
            l++;
        }
        while ((v.at(h)) > pivot) {
            h--;
        }
        if (l >=h) {
            done = true;
        }
        else {
            temp = v.at(l);
            v.at(l) = v.at(h);
            v.at(h) = temp;
            l++;
            h--;
        }
    }
    return h;
}

template<typename T>
void quicksort(T numbers[], int i, int k) {
        int j = 0;
        if (i >= k) {
            return;
        }
     j = partition(numbers, i, k);
     quicksort(numbers, i, j);
     quicksort(numbers, j+1, k);
}
template<typename T>
void quicksort(vector<T> &v, int i, int k) {
        if (i >= k) {
            return;
        }
     int j = partition(v, i, k);
     quicksort(v, i, j);
     quicksort(v, j+1, k);
}


};

#endif 