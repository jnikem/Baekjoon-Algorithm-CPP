#include <bits/stdc++.h>
using namespace std;

string S;
int alpha[26] = {0, };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> S;
	for(char c : S) {
		alpha[c - 'a'] += 1;
	}
	
	for(int i : alpha) {
		cout << i << " ";
	}
    
    return 0;
}
