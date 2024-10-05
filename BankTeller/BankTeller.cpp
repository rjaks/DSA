#include <iostream>
#include <vector>
using namespace std;

vector<string> vip;
vector<string> regular;

void solve(){
    int rank; string command, name;
    cin >> command;
    if (command == "COME"){
        cin >> rank >> name;
        if (rank == 1){
            vip.insert(regular.begin(), name);
        }
        else if (rank == 2){
            regular.insert(regular.begin(), name);
        }
    }
    else if (command == "SERVE"){
        if (vip.size() != 0){
            cout << vip.back() << endl; vip.pop_back();
        }
        else {
            if (regular.size() != 0){
                cout << regular.back() << endl; regular.pop_back();
            }
            else cout << "EMPTY\n";
        }
    }
}

int main(){
    int N;
    cin >> N;

    for (int i = 0 ; i < N; i++) { solve(); }

    return 0;
}