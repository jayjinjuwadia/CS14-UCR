#include <string>
#include <iostream>
#include <list>
#include <cmath>
#include <vector>
#include <fstream>
#include <iterator>
#include <cstdlib>
using namespace std;

class Hash {
private:

struct Node {
    Node *next;
    unsigned value;
    int count;
    string stval;
    Node() {
        next = NULL;
        count = 0;
        value = 0;
    }
    Node(unsigned val) {
        value = val;
        count = 0;
        next = NULL;
    }
    
};
int collisions;
list<Node> l;
vector<int> lllengths;
public:
void hashslingingslasher(string filename){ 
    ifstream infs;
    string strchar;
    infs.open(filename.c_str());
    if (!infs.is_open()) {
        cout << "Error opening file\n";
        exit(1);
    }
    Node *n;
    while (infs >> strchar) {
            n= new Node(0);
            n->value = strchar.at(0)*strchar.at(strchar.size()-2) + strchar.at(1)*strchar.at(strchar.size()-1);
            
            
            n->stval = strchar; 

            l.push_back(*n);
 
    }
    Node *c;
     unsigned i = 0;
     unsigned g = 0;
    for (list<Node>::iterator j = l.begin(); j != l.end(); j++) {
        if (j->count > 1) {
            g = j->value % l.size();
            list<Node>::iterator b = l.begin();
            while (g) {
            b++;
            g--;
            }
            Node* x = b->next;
            if (x == NULL && b->value == 0) {
                b->value = j->value;
                b->stval = j->stval;
                b->count = 1;
            }
            else if (x == NULL) {b->next = new Node(j->value); b->next->stval = j->stval; b->count++; collisions++;}
            else if(b->value == 0) {
            collisions+=1;
            while (x->next != NULL) {
                collisions++;
                x = x->next;
            }
             x->next = new Node(j->value);
            x->next->stval = j->stval;
            }
            else {
                collisions+=2;
            while (x->next != NULL) {
                collisions++;
                x = x->next;
            }
            
            x->next = new Node(j->value);
            x->next->stval = j->stval;
            }
            b->count++;
            c = j->next;
            j->count--;
            if (c == NULL) {j->value = 0;j->stval ="";j->count =0;}
            else {
            j->value = j->next->value;
            j->stval = j->next->stval;
            while ( c->next != NULL) {
                c-> value = c->next->value;
                c->stval = c->next->stval;
                if (c->next->next == NULL) {
                    break;
                }
                c = c->next;
            }
            if (c->next != NULL) {
            delete c->next;
            c->next = NULL;
            j->count--;
            }
            else {
                delete j->next;
                j->next = NULL;
                j->count--;
            }
        }
        }
    
        else if (j->count == 0 && j->value != 0) {
            list<Node>::iterator p = l.begin();
            i = j->value % l.size();
            while (i) {
            p++;
            i--;
            }
            Node *t = p->next;
            if (t == NULL && p->value == 0) {
                p->value = j->value;
                p->stval = j->stval;
                p->count = 1;
            }
            else if (t == NULL) {
                collisions++;
                p->next = new Node(j->value);
                p->next->stval = j->stval;
                p->count++;
            }
            else if (p->value == 0){
            collisions+=1;
            while (t->next != NULL) {
                t = t->next;
                collisions++;
            }
            t->next = new Node(j->value);
            t->next->stval = j->stval;
            p->count++;
            }
            else {
                collisions+=2;
            while (t->next != NULL) {
                t = t->next;
                collisions++;
            }
            t->next = new Node(j->value);
            t->next->stval = j->stval;
            p->count++;
            }
            j->count = 0;
            j->value = 0;
            j->stval = "";
        }
    }
    
    for (list<Node>::iterator h = l.begin();h != l.end();h++) {
        if (h->value == 0 && h->next != NULL) {
            h->value = h->next->value;
            h->stval = h->next->stval;
            
            Node *o = h->next;
            if (o->next == NULL) {
                delete h->next;
                h->next = NULL;
                h->count++;
            }
            else {
            while (o->next != NULL) {
            o->value = o->next->value;
            o->stval = o->next->stval;
            if (o->next->next == NULL) {
                break;
            }
            o = o->next;
            }
            delete o->next;
            o->next = NULL;
            }
        }
    }
 /*   for (list<Node>::iterator f = l.begin(); f != l.end();f++ ) {
        if (f->next != NULL) {
            Node *u = f->next;
            if (f->next->stval == f->stval) {
                delete f->next;
                f->next = NULL;
            }
            else {
                while (u->next != NULL) {
                    if (u->stval == u->next->stval) {
                        delete u->next;
                        u->next = NULL;
                        break;
                    }
                    u = u->next;
                }
            }
        }
    }*/
    infs.close();
}
void hornerhash(string filename) {
    ifstream infs;
    string strchar;
    infs.open(filename.c_str());
    if (!infs.is_open()) {
        cout << "Error opening file\n";
        exit(1);
    }
    Node *n;
    while (infs >> strchar) {
            n= new Node(0);
            for (unsigned z = 0; z < strchar.size(); z++) {
                n->value += strchar.at(z)*(strchar.size() - z - 1) *pow(37,z);
            }
            
            
            n->stval = strchar; 

            l.push_back(*n);
 
    }
    Node *c;
     unsigned i = 0;
     unsigned g = 0;
    for (list<Node>::iterator j = l.begin(); j != l.end(); j++) {
        if (j->count > 1) {
            g = j->value % l.size();
            list<Node>::iterator b = l.begin();
            while (g) {
            b++;
            g--;
            }
            Node* x = b->next;
            if (x == NULL && b->value == 0) {
                b->value = j->value;
                b->stval = j->stval;
                b->count++;
            }
            else if (x == NULL) {b->next = new Node(j->value); b->next->stval = j->stval; b->count++;collisions++;}
            else if (b->value == 0) {
                collisions +=1;
                while (x->next != NULL) {
                collisions++;
                x = x->next;
            }
            
            x->next = new Node(j->value);
            x->next->stval = j->stval;
            b->count++;
            }
            else {
                collisions+= 2;
            while (x->next != NULL) {
                collisions++;
                x = x->next;
            }
            
            x->next = new Node(j->value);
            x->next->stval = j->stval;
            b->count++;
            }
            c = j->next;
            j->count--;
            if (c == NULL) {j->value = 0;j->stval ="";j->count =0;}
            else {
            j->value = j->next->value;
            j->stval = j->next->stval;
            while ( c->next != NULL) {
                c-> value = c->next->value;
                c->stval = c->next->stval;
                if (c->next->next == NULL) {
                    break;
                }
                c = c->next;
            }
            if (c->next != NULL) {
            delete c->next;
            c->next = NULL;
            j->count--;
            }
            else {
                delete j->next;
                j->next = NULL;
                j->count--;
            }
        }
        }
    
        else if (j->count == 0 && j->value != 0) {
            list<Node>::iterator p = l.begin();
            i = j->value % l.size();
            while (i) {
            p++;
            i--;
            }
            Node *t = p->next;
            if (t == NULL && p->value == 0) {
                p->value = j->value;
                p->stval = j->stval;
                p->count =1;
            }
            else if (t == NULL) {
                collisions++;
                p->next = new Node(j->value);
                p->next->stval = j->stval;
                p->count++;
            }
            else if (p->value == 0){
                collisions+=1;
            while (t->next != NULL) {
                collisions++;
                t = t->next;
            }
                        t->next = new Node(j->value);
            t->next->stval = j->stval;
            p->count++;
            }
            else {
                collisions += 2;
            while (t->next != NULL) {
                collisions++;
                t = t->next;
            }
                        t->next = new Node(j->value);
            t->next->stval = j->stval;
            p->count++;
            }
             j->value = 0;
                j->stval = "";
                j->count = 0;
            }
   
              
            
        }
    
    
    for (list<Node>::iterator h = l.begin();h != l.end();h++) {
        if (h->value == 0 && h->next != NULL) {
            h->value = h->next->value;
            h->stval = h->next->stval;
            
            Node *o = h->next;
            if (o->next == NULL) {
                delete h->next;
                h->next = NULL;
                h->count++;
            }
            else {
            while (o->next != NULL) {
            o->value = o->next->value;
            o->stval = o->next->stval;
            if (o->next->next == NULL) {
                break;
            }
            o = o->next;
            }
            delete o->next;
            o->next = NULL;
            }
        }
    }
  /*  for (list<Node>::iterator f = l.begin(); f != l.end();f++ ) {
        if (f->next != NULL) {
            Node *u = f->next;
            if (f->next->stval == f->stval) {
                delete f->next;
                f->next = NULL;
            }
            else {
                while (u->next != NULL) {
                    if (u->stval == u->next->stval) {
                        delete u->next;
                        u->next = NULL;
                        break;
                    }
                    u = u->next;
                }
            }
        }
    }*/
    infs.close();
}
void hashbythree(string filename) {
    ifstream infs;
    string strchar;
    infs.open(filename.c_str());
    if (!infs.is_open()) {
        cout << "Error opening file\n";
        exit(1);
    }
    Node *n;
    while (infs >> strchar) {
            n= new Node(0);
            n->value = strchar.at(0) + (27*strchar.at(1)) + (729*strchar.at(2));
            
            n->stval = strchar; 

            l.push_back(*n);
 
    }
    Node *c;
     unsigned i = 0;
     unsigned g = 0;
    for (list<Node>::iterator j = l.begin(); j != l.end(); j++) {
        if (j->count > 1) {
            g = j->value % l.size();
            list<Node>::iterator b = l.begin();
            while (g) {
            b++;
            g--;
            }
            Node* x = b->next;
            if (x == NULL && b->value == 0) {
                b->value = j->value;
                b->stval = j->stval;
                b->count =1;
            }
            else if (x == NULL) {b->next = new Node(j->value); b->next->stval = j->stval; b->count++;collisions++;}
            else if (b->value == 0){
                collisions+=1;
            while (x->next != NULL) {
                collisions++;
                x = x->next;
            }
             x->next = new Node(j->value);
            x->next->stval = j->stval;
            b->count++;
            }
            else {
                collisions+=2;
                while (x->next != NULL) {
                    collisions++;
                    x = x->next;
                }
                            x->next = new Node(j->value);
            x->next->stval = j->stval;
            b->count++;
            }
            c = j->next;
            j->count--;
            if (c == NULL) {j->value = 0;j->stval ="";j->count =0;}
            else {
            j->value = j->next->value;
            j->stval = j->next->stval;
            while ( c->next != NULL) {
                c-> value = c->next->value;
                c->stval = c->next->stval;
                if (c->next->next == NULL) {
                    break;
                }
                c = c->next;
            }
            if (c->next != NULL) {
            delete c->next;
            c->next = NULL;
            j->count--;
            }
            else {
                delete j->next;
                j->next = NULL;
                j->count--;
            }
        }
        }
    
        else if (j->count == 0 && j->value != 0) {
            list<Node>::iterator p = l.begin();
            i = j->value % l.size();
            while (i) {
            p++;
            i--;
            }
            Node *t = p->next;
            if (t == NULL && p->value == 0) {
                p->value = j->value;
                p->stval = j->stval;
                p->count++;
            }
            else if (t == NULL) {
                collisions++;
                p->next = new Node(j->value);
                p->next->stval = j->stval;
                p->count++;
            }
            else if (p->value == 0){
            collisions++;
            while (t->next != NULL) {
                collisions++;
                t = t->next;
            }
                      t->next = new Node(j->value);
            t->next->stval = j->stval;
            p->count++;
            }
            else {
                collisions+=2;
                while (t->next != NULL) {
                collisions++;
                t = t->next;
            }
                      t->next = new Node(j->value);
            t->next->stval = j->stval;
            p->count++;
            }

            j->count = 0;
            j->value = 0;
            j->stval = "";
        }
}
    
    for (list<Node>::iterator h = l.begin();h != l.end();h++) {
        if (h->value == 0 && h->next != NULL) {
            h->value = h->next->value;
            h->stval = h->next->stval;
            
            Node *o = h->next;
            if (o->next == NULL) {
                delete h->next;
                h->next = NULL;
                h->count++;
            }
            else {
            while (o->next != NULL) {
            o->value = o->next->value;
            o->stval = o->next->stval;
            o = o->next;
            }
            }
        }
    }
    for (list<Node>::iterator f = l.begin(); f != l.end();f++ ) {
        if (f->next != NULL) {
            Node *u = f->next;
            if (f->next->stval == f->stval) {
                delete f->next;
                f->next = NULL;
            }
            else {
                while (u->next != NULL) {
                    if (u->stval == u->next->stval) {
                        delete u->next;
                        u->next = NULL;
                        break;
                    }
                    u = u->next;
                }
            }
        }
    }
 infs.close();
}
void modhash(string filename)     {
    ifstream infs;
    string strchar;
    infs.open(filename.c_str());
    if (!infs.is_open()) {
        cout << "Error opening file\n";
        exit(1);
    }
    Node *n;
    while (infs >> strchar) {
            n= new Node(0);
            for (unsigned z = 0; z < strchar.size(); z++) {
                n->value += strchar.at(z);
            }
            
            
            n->stval = strchar; 

            l.push_back(*n);
 
    }
    Node *c;
     unsigned i = 0;
     unsigned g = 0;
    for (list<Node>::iterator j = l.begin(); j != l.end(); j++) {
        if (j->count > 1) {
            g = j->value % l.size();
            list<Node>::iterator b = l.begin();
            while (g) {
            b++;
            g--;
            }
            Node* x = b->next;
            if (x == NULL && b->value == 0) {
                b->value = j->value;
                b->stval = j->stval;
                b->count++;
            }
            else if (x == NULL) {b->next = new Node(j->value); b->next->stval = j->stval; b->count++;collisions++;}
            else if (b->value == 0) {
                collisions +=1;
                while (x->next != NULL) {
                collisions++;
                x = x->next;
            }
            
            x->next = new Node(j->value);
            x->next->stval = j->stval;
            b->count++;
            }
            else {
                collisions+= 2;
            while (x->next != NULL) {
                collisions++;
                x = x->next;
            }
            
            x->next = new Node(j->value);
            x->next->stval = j->stval;
            b->count++;
            }
            c = j->next;
            j->count--;
            if (c == NULL) {j->value = 0;j->stval ="";j->count =0;}
            else {
            j->value = j->next->value;
            j->stval = j->next->stval;
            while ( c->next != NULL) {
                c-> value = c->next->value;
                c->stval = c->next->stval;
                if (c->next->next == NULL) {
                    break;
                }
                c = c->next;
            }
            if (c->next != NULL) {
            delete c->next;
            c->next = NULL;
            j->count--;
            }
            else {
                delete j->next;
                j->next = NULL;
                j->count--;
            }
        }
        }
    
        else if (j->count == 0 && j->value != 0) {
            list<Node>::iterator p = l.begin();
            i = j->value % l.size();
            while (i) {
            p++;
            i--;
            }
            Node *t = p->next;
            if (t == NULL && p->value == 0) {
                p->value = j->value;
                p->stval = j->stval;
                p->count =1;
            }
            else if (t == NULL) {
                collisions++;
                p->next = new Node(j->value);
                p->next->stval = j->stval;
                p->count++;
            }
            else if (p->value == 0){
                collisions+=1;
            while (t->next != NULL) {
                collisions++;
                t = t->next;
            }
                        t->next = new Node(j->value);
            t->next->stval = j->stval;
            p->count++;
            }
            else {
                collisions += 2;
            while (t->next != NULL) {
                collisions++;
                t = t->next;
            }
                        t->next = new Node(j->value);
            t->next->stval = j->stval;
            p->count++;
            }
             j->value = 0;
                j->stval = "";
                j->count = 0;
            }
   
              
            
        }
    
    
    for (list<Node>::iterator h = l.begin();h != l.end();h++) {
        if (h->value == 0 && h->next != NULL) {
            h->value = h->next->value;
            h->stval = h->next->stval;
            
            Node *o = h->next;
            if (o->next == NULL) {
                delete h->next;
                h->next = NULL;
                h->count++;
            }
            else {
            while (o->next != NULL) {
            o->value = o->next->value;
            o->stval = o->next->stval;
            if (o->next->next == NULL) {
                break;
            }
            o = o->next;
            }
            delete o->next;
            o->next = NULL;
            }
        }
    }
  /*  for (list<Node>::iterator f = l.begin(); f != l.end();f++ ) {
        if (f->next != NULL) {
            Node *u = f->next;
            if (f->next->stval == f->stval) {
                delete f->next;
                f->next = NULL;
            }
            else {
                while (u->next != NULL) {
                    if (u->stval == u->next->stval) {
                        delete u->next;
                        u->next = NULL;
                        break;
                    }
                    u = u->next;
                }
            }
        }
    }*/
    infs.close();
}
int listlength(Node* t) {
    int i = 0;
    while (t != NULL) {
        i++;
        t= t->next;
    }
    return i;
}
void processFile() {
     string filename;
    cout << "Enter input file name:\n";
    cin  >> filename;
    cout << "How would you like to hash this function?\n" << "1: Modulo Hash\n" << "2: Hash First Three \n" << "3: Horner Hash \n" << "4: HSS \n"<< "5: Quit\n";
    int input;
    cin >> input;
    if (input == 1) {
        modhash(filename);
    }
    else if (input == 2) {
        hashbythree(filename);
    }
    else if (input == 3) {
        hornerhash(filename);
    }
    else if (input == 4) {
        hashslingingslasher(filename);
    }
    else if (input == 5) {
        cout << "Quitting\n";
        exit(1);
    }
    else {
        cout << "Input invalid\n";
        exit(1);
    }
    
}

void print() {
    /**/
    string st;
    cout << "Enter output filename\n";
    cin >> st;
    ofstream ofs;
    ofs.open(st.c_str());
    if (!ofs.is_open()) {
        cout << "Error opening output file\n";
        exit(1);
    }
    int flag = 0;
    for (list<Node>::iterator i = l.begin(); i != l.end(); i++) {
        if (i->count >= 0) {
            Node *t = i->next;
            if (i->stval == "") {flag +=1;}
            else {
            ofs << i->stval << " "<< i->count <<", ";
            }
            if (t == NULL) {flag+=1;}
            while (t != NULL) {
                ofs << t->stval <<" " << t->count << ", ";
                t = t->next;
            }
            if (flag != 2) {
           ofs << endl;
            }
            flag = 0;
        }
    }
} 
void size() {
    int size = 0;
    for (list<Node>::iterator i = l.begin(); i != l.end(); i++) {
        if (i->value != 0) {
        size = 1 + listlength(i->next);
        }
        else {
            size = listlength(i->next);
        }
        lllengths.push_back(size);
    }
}
int avglength() {
    int sum = 0;
    int size = 0;
    for (unsigned i = 0; i < lllengths.size(); i++) {
        sum += lllengths.at(i);
        if (lllengths.at(i) != 0) {
            size++;
        }
    }
    return sum / size;
}
int longestsize() {
    int maxsize = 0;
    size();
    for (unsigned i = 0; i < lllengths.size(); i++) {
        if (lllengths.at(i) == 0) {
            
        }
        else if (lllengths.at(i) > maxsize) {
            maxsize = lllengths.at(i);
        }
    }
    return maxsize;
}
void printStats() {
    int longest = longestsize();
    int average = avglength();
    cout <<"Longest list size: " <<longest << endl;
    cout << "Average list length: " << average << endl;
    cout << "Number of collisions: " <<collisions << endl;
}

};