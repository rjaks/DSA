#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const string operators = "+-*/";
const string numbers = "0123456789";
vector<char> stack;
int total;

// self-explanatory(?) defined functions
string solve(string);
bool isOperator(char);
bool isNumber(char);
bool isLeftParanthesis(char);
bool isRightParanthesis(char);
void push(char);
void pop();
int precedence(char);
void getTotal(string);

// boolean evaluators and stack functions
// internet's jargons: string::npos means until the end of string; the functions return false if they find no match
bool isOperator(char c) { return operators.find(c) != string::npos; } 
bool isNumber(char c) { return numbers.find(c) != string::npos; }
bool isLeftParanthesis(char c){ return c == '('; }
bool isRightParanthesis(char c){ return c == ')'; }
void push(char c){ stack.insert(stack.begin(), c); }
void pop(){ stack.erase(stack.begin()); }

int precedence(char c){
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else return 0;
}

// Unsolved: Needs revision
// ISSUE: Incorrect output
void getTotal(string result){ 
    istringstream iss(result);
    int value = 0;
    char op = '+';
    while (iss >> value){
        if (op == '+') total += value;
        else if (op == '-') total -= value;
        else if (op == '*') total *= value;
        else if (op == '/') total /= value;
    }
}

string solve(string infixExpression){
    string postfix, result;

    for (char j : infixExpression){ 
        if (isNumber(j)) postfix += j;
        else if (isLeftParanthesis(j)) push(j);
        else if (isRightParanthesis(j)) {
            while (stack.empty() == false && stack[0] != '(') {
                postfix += stack[0];
                pop();
            }
            pop(); // pops the left paranthesis
        }
        else if (isOperator(j)){
            while (stack.empty() != true && precedence(stack[0]) >= precedence(j)){ // checks if the top operator in the stack is of higher precedence than the current operator
                postfix += stack[0];
                pop();
            }
            push(j); // pushes the current operator
        }
    }

    while (stack.empty() == false) {
        postfix += stack[0];
        pop();
    }

    for (char i: postfix) {
        result += i;
        result += ' ';
    }
    
    getTotal(infixExpression);

    return result + "= " + to_string(total);
}

int main() {
    int E;
    cin >> E;
    string C;

    for (int i = 0; i < E; i++) {
        cin.ignore();
        getline(cin, C); 
        cout << solve(C) << endl;
    }
    return 0;
}