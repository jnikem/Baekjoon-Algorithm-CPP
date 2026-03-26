#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char c) {
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    if (addr == 0) return;
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    string S;
    cin >> S;

    int cursor = 0;
    for (auto c : S) {
        insert(cursor, c);
        cursor = nxt[cursor];
    }

    int M;
    cin >> M;
    while (M--) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'L':
                if (pre[cursor] != -1) cursor = pre[cursor];
                break;
            case 'D':
                if (nxt[cursor] != -1) cursor = nxt[cursor];
                break;
            case 'B':
                if (cursor != 0) {
                    int target = cursor;
                    cursor = pre[cursor];
                    erase(target);
                }
                break;
            case 'P':
                char chr;
                cin >> chr;
                insert(cursor, chr);
                cursor = nxt[cursor];
                break;
        }
    }

    int cur = nxt[0];
    while (cur != -1) {
        cout << (char)dat[cur];
        cur = nxt[cur];
    }

    return 0;
}