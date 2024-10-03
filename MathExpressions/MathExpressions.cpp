#include <iostream>
#include <vector>
using namespace std;

const string paranthesis = "()";
const string operators = "+-*/";
const string numbers = "0123456789";
vector<char> stack;

// self-explanatory(?) defined functions
string solve(string);
bool isOperator(char);
bool isNumber(char);
bool isParanthesis(char);
void push(char);
void pop();
int precedence(char);

// getters and setters
bool isOperator(char c) { return operators.find(c) != string::npos; }
bool isNumber(char c) { return numbers.find(c) != string::npos; }
bool isParanthesis(char c) { return paranthesis.find(c) != string::npos; }
bool isLeftParanthesis(char c){ return c == '('; }
bool isRightParanthesis(char c){ return c == ')'; }
void push(char c){ stack.insert(stack.begin(), c); }
void pop(){ stack.erase(stack.begin()); }
int precedence(char c){
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
}

string solve(string expression){
    string infix, postfix;

    for (char k : expression) {
        if (k != ' ') infix += k; 
    }

    for (char j : infix){ 
        if (isNumber(j)) postfix += j;
        else if (isLeftParanthesis(j)) push(j);
        else if (isRightParanthesis(j)) {
            while (stack.empty() == false && stack[0] != ')') {
                postfix += stack[0];
                pop();
            }
            pop(); // pops the left paranthesis
        }
        else if (isOperator(j)){
            while (stack.empty() != true && precedence(stack[0]) >= precedence(j)){
                postfix += stack[0];
                pop();
            }
            push(j);
        }
    }

    while (stack.empty() != true) {
        postfix += stack[0];
        pop();
    }
    
    return postfix;
}

int main() {
    int E;
    cin >> E;
    string expression;
    cin.ignore();

    for (int i = 0; i < E; i++) {
        getline(cin, expression); 
        cout << solve(expression) << endl;
    }
    return 0;
}