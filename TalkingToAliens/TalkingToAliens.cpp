#include<iostream>
using namespace std;

const string conversion = "0123456789abcdefghijklmnopqrstuvwxyz";

class Node {
    public:
        int value;
        Node* next;
};

Node *head = NULL;

void solve(int x, int y);
void pushNode(int n);
void displayResult();

void solve(int x, int y){
    while (x != 0){
        int n = x % y;
        x /= y;
        pushNode(n);
    }
    displayResult();
}

void pushNode(int n){
    Node* node = new Node();
    node->value = n;
    node->next = head;
    head = node;
}

void displayResult(){
    Node *temp = head;
    while (temp != NULL){
        cout << conversion[temp->value];
        Node* current = temp;
        temp = temp->next;
        delete current;
    }
    head = NULL;
}

int main(){
    int x, y;
    
    while (cin >> x >> y){
        solve(x,y);
        cout << endl;
    }

    return 0;
}