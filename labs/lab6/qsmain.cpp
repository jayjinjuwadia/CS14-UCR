#include "Quicksort.h"

int main() {
    vector<string> v;
    vector<char> c;
    vector<int> l;
    cout << "QUICK SORT ARRAY TEST:\n";
    int array[] = {5,1, 11, 29, 84,24 ,56,25,28,785,63, 92,0, 19, -155,-12,4};
    for (int s = 0; s < 16; s++) {
        l.push_back(array[s]);
    }
    cout << "UNSORTED:";
    for (int i = 0; i < 16; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    Quicksort::quicksort(array, 0, 16);
    for (unsigned f = 0; f < 16; f++) {
        cout << array[f] << " ";
    }
    cout << endl;
    cout << "QUICK SORT VECTOR TEST: STRING\n";
    cout << "UNSORTED: ";
    v.push_back("Mary");
    v.push_back("Tom");
    v.push_back("Tommy");
    v.push_back("Andrew");
    v.push_back("Rachel");
    v.push_back("John");
    v.push_back("Jon");
    v.push_back("Andrew");
    for (unsigned j = 0; j < v.size(); j++) {
        cout << v.at(j) << " ";
    }
    cout << endl;
      cout << "SORTED: ";
    Quicksort::quicksort(v, 0, v.size() - 1);
    for (unsigned d = 0; d < v.size(); d++ ) {
        cout << v.at(d) << " ";
    }
    cout << endl;
    cout << "QUICK SORT VECTOR TEST: CHAR\n";
    c.push_back('a');
    c.push_back('k');
    c.push_back('w');
    c.push_back('g');
    c.push_back('j');
    c.push_back('f');
    c.push_back('o');
    c.push_back('p');
    c.push_back('b');
    c.push_back('m');
    c.push_back('z');
    c.push_back('x');
    cout << "UNSORTED: ";
    for (unsigned b = 0; b < v.size(); b++) {
        cout << c.at(b) << " ";
    }
    cout << endl;
    Quicksort::quicksort(c,0,c.size()-1);
    cout << "SORTED: ";
    for (unsigned e = 0; e < v.size(); e++) {
        cout << c.at(e) << " ";
    }
    cout << endl;
    cout << "QUICK SORT VECTOR TEST: INT\n";
    cout << "UNSORTED: ";
    for (unsigned b = 0; b < l.size(); b++) {
        cout << l.at(b) << " ";
    }
    cout << endl;
    Quicksort::quicksort(l,0,l.size()-1);
    cout << "SORTED: ";
    for (unsigned e = 0; e < l.size(); e++) {
        cout << l.at(e) << " ";
    }
    cout << endl;
    return 0;
}