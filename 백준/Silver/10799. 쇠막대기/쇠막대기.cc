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
    
    cin >> str;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '(') {
            S.push(str[i]);
        }
        else {
            if (str[i-1] == '(') {
                S.pop();
                ans += S.size();
                }
            else {
                ans++;
                S.pop();
            }
        }
    }   
    cout << ans;
    
    return 0;
}