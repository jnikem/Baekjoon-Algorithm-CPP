#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> S;
    int N, X;
    cin >> N;

    while(N--){
        string cmd;
        cin >> cmd;
        if (cmd == "push"){
            cin >> X;
            S.push(X);
            }
        else if (cmd == "pop"){
            if (S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        }
            
        else if (cmd == "size"){
            cout << S.size() << '\n';
        }
            
        else if (cmd == "empty"){
            cout << S.empty() << '\n';
        }
            
        else {
            if (S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n';
            }
        }
    }
        
    return 0;
}