#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack<pair<int,int>> T;
    
    for (int i = 0; i < N; i++){
        int height;
        cin >> height;

        while (!T.empty() && T.top().first < height) T.pop();

        if (T.empty()) cout << 0 << " "; 

        else {
            cout << T.top().second << " ";
        }

        T.push({height, i + 1});
    }
    return 0;
}