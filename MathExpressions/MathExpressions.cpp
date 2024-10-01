#include<iostream>
#include<vector>
using namespace std;

const string numbers = "0123456789";
const string operators = "+-*/^";
const string parantheses = "()";
bool isNumber, isOperator, isParanthesis, validOperation;
vector<char> op;
char parOp;
string output = "";

void solve(string);
void check(char);
void pop();
void display();

// 5 + 7 - (5 * 3) / 8
// 5 7 + 5 3 * - 8 /

void solve(string C){
    for (int i = 0; i < C.length(); i++){
        isNumber = false, isOperator = false, isParanthesis = false, validOperation = true;
        check(C[i]);

        if (isOperator) {
            if (C[i+2] == '(') char parOp = C[i];
            op.push_back(C[i]);
        }
        else if (isNumber) {
            if (op.size() > 0){
                output += C[i];
                pop();
            }
            else output += C[i];
        }   
        else continue;
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

void pop(){
    output += op[0];
    op.erase(op.begin());
}

void display(){
    for (char k: output) cout << k << " ";
}

int main(){
    int E;
    cin >> E;

    for (int i = 0; i < E; i++){
        string C;
        cin.ignore();
        getline(cin, C);
        solve(C);
        display();
    }

    return 0;
}