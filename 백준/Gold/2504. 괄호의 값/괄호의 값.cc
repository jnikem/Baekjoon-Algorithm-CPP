#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;
    string str;
    int ans = 0;
    int idx = 1;
    bool balanced = true;

    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            S.push(str[i]);
            idx *= 2;
        }
        else if (str[i] == '['){
            S.push(str[i]);
            idx *= 3;
        }
        else if (str[i] == ')') {
            if (!S.empty() && S.top() == '(') {
                if (str[i-1] == '('){
                    ans += idx;
                }
                S.pop();
                idx /= 2;
            }
            else {
                balanced = false;
                break;
            }
        }
        else {
            if (!S.empty() && S.top() == '[') {
                if (str[i-1] == '['){
                ans += idx;
                }
                S.pop();
                idx /= 3;
            }
            else {
                balanced = false;
                break;
            }
        }
    }

    if (S.empty() && balanced == true) {
        cout << ans;
    }
    else {
        cout << 0;
    }

    return 0;
}