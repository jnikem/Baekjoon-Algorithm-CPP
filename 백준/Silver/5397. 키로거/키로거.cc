#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MX = 1000005;
int pre[MX], nxt[MX];
char dat[MX];
int unused = 1;

void insert(int addr, char chr) {
    dat[unused] = chr;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traversal(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    int T, cursor;
    cin >> T;
    
    while (T--) {
        cin >> S;
        cursor = 0;
        unused = 1;
        nxt[0] = -1;
        
        for (char chr : S){
            if (chr == '<') {
                 if (pre[cursor] != -1) 
                 cursor = pre[cursor];
            }
            else if (chr == '>') {
                if (nxt[cursor] != -1) 
                cursor = nxt[cursor];
            }
            else if (chr == '-') {
                if (cursor != 0) {
                    erase(cursor);
                    cursor = pre[cursor];
                }
            }
            else {
                insert(cursor, chr);
                cursor = nxt[cursor];
            }
        }
        traversal();
    }
    
    return 0;
}