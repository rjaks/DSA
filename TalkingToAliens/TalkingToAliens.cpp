#include<iostream>
using namespace std;

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
    if (head == NULL) head = node;
    else{
        Node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = node;
    }
}

void displayResult(){
    while (head != NULL){
        Node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        cout << temp->value;
        Node *temp2 = head;
        while (temp2->next != temp) temp2 = temp2->next;
        delete temp;
        temp2->next = NULL;
    }
}

int main(){
    int x, y;
    
    while (cin >> x >> y){
        solve(x,y);
        cout << endl;
    }

    return 0;
}