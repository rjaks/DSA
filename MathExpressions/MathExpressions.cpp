#include<iostream>
using namespace std;

const string numbers = "0123456789";
const string operators = "+-*/^";
const string parantheses = "()";
bool isNumber, isOperator, isParanthesis;

class Node {
    public:
        char value;
        Node* next;
};

void solve();
void check(char);
void push(char);
void display();

void solve(string C){
    for (int i = 0; i < C.length(); i++){
        isNumber = false, isOperator = false, isParanthesis = false;
        check(C[i]);
        if (isParanthesis) check(C[i+1]);
        else if (isNumber) push(C[i]);
    }
}

void check(char c){
    for (char k : numbers){
        if (k == c) { isNumber = true; break; }
    }
    for (char k : operators){
        if (k == c) { isOperator = true; break; }
    }
    for (char k : parantheses){
        if (k == c) { isParanthesis = true; break; }
    }
}

int main(){
    int E;
    cin >> E;

    for (int i = 0; i < E; i++){
        string C;
        cin.ignore();
        getline(cin, C);
        solve(C);
    }

    return 0;
}