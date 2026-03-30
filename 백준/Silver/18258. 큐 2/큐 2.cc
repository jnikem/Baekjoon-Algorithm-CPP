#include <iostream>

#include <queue>

#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    

    int N, X;

    cin >> N;

    queue<int> Q;

    string cmd;

    

    while(N--){

        cin >> cmd;

        

        if (cmd == "push"){

            cin >> X;

            Q.push(X);

        }

        else if (cmd == "pop"){

            if (Q.empty()) cout << -1 << "\n";

            else {

                cout << Q.front() << "\n";

                Q.pop();

            }

        }

        else if (cmd == "size"){

            cout << Q.size() << "\n";

        }

        else if (cmd == "empty"){

            cout << Q.empty() << "\n";

        }

        else if (cmd == "front"){

            if (Q.empty()) cout << -1 << "\n";

            else cout << Q.front() << "\n";

        }

        else {

            if (Q.empty()) cout << -1 << "\n";

            else cout << Q.back() << "\n";

        }

    }

    

    return 0;

}