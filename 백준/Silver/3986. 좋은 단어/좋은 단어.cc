#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int ans = 0;
    string str;
    
    cin >> N;
    while (N--) {
        stack<char> S;
        cin >> str;

        for (char c : str) {
            if (!S.empty() && S.top() == c) {
                S.pop();
            } else {
                S.push(c);
            }
        }

    if (S.empty()) ans++;
}

    cout << ans;
    
    return 0;

}