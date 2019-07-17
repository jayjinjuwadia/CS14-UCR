#include "Template.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;
/*
Algorithm RPN Evaluation
let P be the given postfix expression;
create empty stack S;
for each symbol s in P do
if is_number(s)
then S.push(s)
else // s is an operator, + or *
if S.empty() 
then report_error()
else
b <- S.pop();
if S.empty() 
then report_error()
else
a <- S.pop();
compute c <- a s b;
S.push(c);
v = S.pop();
if not S.empty()
then report_error()
else print(v);
*/

bool IsOperator(const char &c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

bool HasHigherPrecedence(const char &c1, const char &c2) {
    int c1prec = 0;
    int c2prec = 0;
    if (c1 == '+' || c1 == '-') {
        c1prec++;
    }
    if (c2 == '*' || c2 == '-') {
        c2prec++;
    }
    if (c1 == '*' || c1 == '/') {
        c1prec += 2;
    }
     if (c2 == '*' || c2 == '/') {
        c2prec += 2;
    }
    if (c1prec > c2prec) {
        return true;
    }
    else {
        return false;
    }
}

string InfixToPostfix() {
    ifstream infs;
    infs.open("postfix.txt");
    char infixstack;
    string str;
    string postfix;
    while (infs >> infixstack) {
        str.push_back(infixstack);
    }
	Stack<char> S;
	for(unsigned i = 0; i < str.length();i++) {
		if(str[i] == ' ' || str[i] == ',') continue; 
		else if(IsOperator(str[i])) {
			while(!S.is_empty() && S.top() != '(' && HasHigherPrecedence(S.top(),str[i])) {
				postfix+= S.top();
				S.pop();
			}
			S.push(str[i]);
		}
		else if(isdigit(str[i])) {
			postfix +=str[i];
		}

		else if (str[i] == '(')  {
			S.push(str[i]);
		}

		else if(str[i] == ')')  {
			while(!S.is_empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.is_empty()) {
		postfix += S.top();
		S.pop();
	}
cout << postfix << endl;
	return postfix;
}

void rpneval() {
    int b;
    int a;
    int c;
    int v;
    Stack<int> stacker;
    string str = InfixToPostfix();
    for (unsigned i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) {
            stacker.push(str[i] - 48);
            cout << stacker.top() << endl;
        }
        else {
            if (stacker.is_empty()) {
                throw std::underflow_error("Stack Underflow\n");
            }
            else {
                 b = stacker.top();
                 stacker.pop();
                 if (stacker.is_empty()) {
                     throw std::underflow_error("Stack Underflow\n");
                 }
                 else {
                     a = stacker.top();
                     stacker.pop();
                     if (str[i] == '+') {
                        c = a + b;
                        stacker.push(c);
                        cout << c << endl;
                        cout << stacker.top() << endl;
                    }
                     else if (str[i] == '*') {
                         c = a * b;
                         stacker.push(c);
                         cout << stacker.top() << endl;
                     }
                     else if (str[i] == '-') {
                         c = a - b;
                         stacker.push(c);
                         cout << stacker.top() << endl;
                     }
                     else {
                         c = a / b;
                         stacker.push(c);
                         cout << stacker.top() << endl;
                     }
                 }
            }
        }
    }
    v = stacker.top();
    if (!stacker.is_empty()) {
        throw std::underflow_error("Stack Underflow\n");
    }
    else {
        cout << v << endl;
    }
}

int main () {
    Stack<int> s;
    s.push(5);
    cout << s.top() << endl;
    cout << s.is_empty() << endl;
    s.pop();
    //cout << s.top() << endl;
    cout << s.is_empty() << endl;
    //s.pop();
    Stack<char> c;
    c.push('a');
    cout << c.top() << endl;
    c.push('h');
    cout << c.top() << endl;
    c.push('z');
    cout << c.top() << endl;
    cout << c.is_empty() << endl;
    c.pop();
    cout << c.top() << endl;
    cout << c.is_empty() << endl;
    c.pop();
    cout << c.top() << endl;
    cout << c.is_empty() << endl;
    c.pop();
    //cout << c.top() << endl;
    cout << c.is_empty() << endl;
    Stack<string> str;
    str.push("What's ");
    cout << str.top() << endl;
    str.push("good ");
    cout << str.top() << endl;
    str.push("bru\n");
    cout << str.top() << endl;
    cout << str.is_empty() << endl;
    str.pop();
    cout << str.top() << endl;
    cout << str.is_empty() << endl;
    str.pop();
    cout << str.top() << endl;
    cout << str.is_empty() << endl;
    str.pop();
    //cout << str.top() << endl;
    cout << str.is_empty() << endl;
    cout << "CHAR TEST:" << endl;
    Stack<char> charstack;
    ifstream infs;
    infs.open("testchar.txt");
    char inputchar;
    while (infs >> inputchar) {
        cout << inputchar << " ";
        charstack.push(inputchar);
    }
    cout << endl << endl;
    cout << "Deleting:" << endl;
    while (!charstack.is_empty()) {
        cout << charstack.top() << " ";
        charstack.pop();
    }
   // cout << charstack.top() << endl;
     cout << endl;
    cout << "STRING TEST:" << endl;
    infs.close();
    infs.clear();
    infs.open("teststring.txt");
    Stack<string> stringstack;
    string inputstring;
    while (infs >> inputstring) {
        cout << inputstring << " ";
        stringstack.push(inputstring);
    }
    cout << stringstack.top() << endl << endl;
    cout << "Deleting:" << endl;
    while (!stringstack.is_empty()) {
        cout << stringstack.top() << " ";
        stringstack.pop();
    }
    cout << endl;
   // cout << stringstack.top() << endl;
    cout << endl;
    infs.close();
    rpneval();
    return 0;
}