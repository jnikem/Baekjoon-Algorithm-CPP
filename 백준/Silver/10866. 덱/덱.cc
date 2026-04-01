#include <iostream>

#include <deque>

#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    

    int N, X;

    cin >> N;

    deque<int> DQ;

    string cmd;

    

    while(N--){

        cin >> cmd;

        

        if (cmd == "push_front"){

            cin >> X;

            DQ.push_front(X);

        }

        else if (cmd == "push_back"){

            cin >> X;

            DQ.push_back(X);

        }

        else if (cmd == "pop_front"){

            if (DQ.empty()) cout << -1 << "\n";

            else {

                cout << DQ.front() << "\n";

                DQ.pop_front();

            }

        }

        else if (cmd == "pop_back"){

            if (DQ.empty()) cout << -1 << "\n";

            else {

                cout << DQ.back() << "\n";

                DQ.pop_back();

            }

        }

        else if (cmd == "size"){

            cout << DQ.size() << "\n";

        }

        else if (cmd == "empty"){

            cout << DQ.empty() << "\n";

        }

        else if (cmd == "front"){

            if (DQ.empty()) cout << -1 << "\n";

            else cout << DQ.front() << "\n";

        }

        else {

            if (DQ.empty()) cout << -1 << "\n";

            else cout << DQ.back() << "\n";

        }

    }

    

    return 0;

}