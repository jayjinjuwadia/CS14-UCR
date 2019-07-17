// main.cpp
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <list>

using namespace std;

// Display function declarations
void Display(list<int>& l);   // displays std::list to std::out
void Display(int a[], int size); // displays array to std::out

// Sorting function declarations
void MergeSort(list<int>& S);
list<int>& Merge(list<int>& C, list<int>& A, list<int>& B);
void MergeSort(int numbers[], int i, int k);
void Merge(int numbers[], int i, int j, int k); // Merge for array*/
void InsertionSort(int numbers[], int numbersSize); // InsertionSort for array
void InsertionSort(list<int>& S);

// Test function declarations
void TestInsertionSortArray(int a[], int size);     // InsertionSort list test
void TestMergeSortList(list<int>& S);                // MergeSort list test
  
int main() {
 int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
  const int NUMBERS_SIZE = 8;
  const int LARGE_N = 1000;
  
  cout << "ARRAY:\n";
  cout << "UNSORTED: "; 
  Display(numbers, NUMBERS_SIZE);
   
  list<int> seq;   
  for(int i = 0; i < NUMBERS_SIZE; i++)
    seq.push_back(numbers[i]);
    
  cout << "LIST:\n";
  cout << "UNSORTED: ";
  Display(seq);
  
  MergeSort(numbers, 0, NUMBERS_SIZE - 1);
  cout << "ARRAY:\n";
  cout << "SORTED: ";
  Display(numbers, NUMBERS_SIZE);
  
  MergeSort(seq);
  cout << "LIST:\n";
  cout << "SORTED: ";
  Display(seq);
   
  srand((unsigned)time(0));   // seed random number generator
   
  int* a = NULL;              // Pointer to int, initialize to OxO
  a = new int[LARGE_N];   
  
  // Allocate NUMBERS_SIZE ints and save ptr in a.
  list<int> seq2;             // list seq2
  for(int i = 0; i < LARGE_N; i++) {
    a[i] = (rand() % (LARGE_N*LARGE_N)) + 1; // insert into array
    seq2.push_back(a[i]);     // insert into list 
  }

  cout << "Array:\n"; 
  cout << "UNSORTED:";
  Display(a, NUMBERS_SIZE);
   
  cout << "LIST:\n";
  cout << "UNSORTED: ";
  Display(seq2);
   
  MergeSort(a, 0, NUMBERS_SIZE - 1);
   
  cout << "Array:\n"; 
  cout << "SORTED: ";
  Display(a, NUMBERS_SIZE);
  
  MergeSort(seq2);
  cout << "LIST:\n";
  cout << "SORTED: ";
  Display(seq2);
    
  numbers[0] = 20;
  numbers[1] = 10;
  numbers[2] = 79; 
  numbers[3] = 2; 
  numbers[4] = 200;
  numbers[5] = 50;
  numbers[6] = -50;
  numbers[7] = -51;
  
  cout << "UNSORTED: ";
  for(int i = 0; i < NUMBERS_SIZE; ++i) {
   cout << numbers[i] << " ";
  }
  cout << endl;
   
 InsertionSort(numbers, NUMBERS_SIZE);
   
  cout << "SORTED: ";
  for(int i = 0; i < NUMBERS_SIZE; ++i) {
   cout << numbers[i] << " ";
  }
  cout << endl; 
  cout << endl << "INSERTION SORT LIST TEST\n\n";
  int numbers3[] = {55, 9, 1, 20, 12, 1000, 12, 24, 2, -6, 3};
  list<int> listy;
  
  for (int f = 0; f < 11; f++) {
      listy.push_back(numbers3[f]);
  }
  cout << "UNSORTED: ";
  Display(listy);
  cout << endl;
  cout << "SORTED: ";
  InsertionSort(listy);
  Display(listy);
  cout << endl;
  return 0;
}

void Display(int a[], int size) {
 for(int i = 0; i < size; ++i) 
   cout << a[i] << " ";
 cout << endl;
}

void Display(list<int>& S) {
  for(list<int>::iterator it = S.begin(); it != S.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

void MergeSort(list<int>& S) {
    if (S.size() > 1) {
        list<int> S1;
        list <int> S2;
        int s = S.size();
        int k = S.size()/2;
        for (int i = 0; i < k; i++) {
            S1.push_back(S.front());
            S.pop_front();
        }
        for (int j = k; j < s; j++ ) {
            S2.push_back(S.front());
            S.pop_front();
        }
        MergeSort(S1);
        MergeSort(S2);
        Merge(S, S1, S2);
    }
}       

list<int>& Merge(list<int>& C, list<int>& A, list<int>& B) {
    while (!A.empty() && !B.empty()) {
        if (A.front() < B.front()) {
            C.push_back(A.front());
            A.pop_front();
        }
        else {
            C.push_back(B.front());
            B.pop_front();
        }
    }
    while (!B.empty()) {
        C.push_back(B.front());
        B.pop_front();
    }
    while (!A.empty()) {
        C.push_back(A.front());
        A.pop_front();
    }
        
    return C;
}

void MergeSort(int numbers[], int i, int k) {
    if (i < k) {
        int j = (i + k) /2;
        MergeSort(numbers, i, j);
        MergeSort(numbers, j+1 , k);
        Merge(numbers, i, j , k);
    }
    
}       // MergeSort for array*/
void Merge(int numbers[], int i, int j, int k) {
    int mergsize = (k-i) + 1;
    int mergpos = 0;
    int leftpos = i;
    int rightpos = j+1;
    int *mergnum = new int[mergsize];
    while (leftpos <= j && rightpos <= k ) {
        if (numbers[leftpos] < numbers[rightpos]) {
            mergnum[mergpos] = numbers[leftpos];
            leftpos++;
        }
        else {
            mergnum[mergpos] = numbers[rightpos];
            rightpos++;
        }
        mergpos++;
    }
    while (leftpos <= j) {
        mergnum[mergpos] = numbers[leftpos];
        mergpos++;
        leftpos++;
    }
    while (rightpos <= k) {
        mergnum[mergpos] = numbers[rightpos];
        mergpos++;
        rightpos++;
    }
    for (mergpos = 0; mergpos < mergsize; mergpos++) {
        numbers[i+mergpos]= mergnum[mergpos];
        }
}

void InsertionSort(int numbers[], int numbersSize) {
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < numbersSize; i++) {
         j = i;
        while (j > 0 && numbers[j] < numbers[j-1]) {
            temp = numbers[j-1];
            numbers[j-1] = numbers[j];
            numbers[j] = temp;
            j--;
        }
    }
    
}

void InsertionSort(list<int>& S) {
    list<int>::iterator i;
    list<int>::iterator j;
    list<int>::iterator k;
    int temp = 0;
    for (i = S.begin(); i !=S.end();i++) {
        j = i;
        k = j;
        k--;
        while (j != S.begin() && *j < *k) {
            temp = *k;
            *k = *j;
            *j = temp;
            j--;
            k--;
        }
    }
}

