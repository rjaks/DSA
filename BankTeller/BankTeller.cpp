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
            vip.push_back(name);
        }
        else if (rank == 2){
            regular.push_back(name);
        }
    }
    else if (command == "SERVE"){
        if (vip.size() != 0){
            cout << vip.front() << endl; vip.erase(vip.begin());
        }
        else {
            if (regular.size() != 0){
                cout << regular.front() << endl; regular.erase(regular.begin());
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