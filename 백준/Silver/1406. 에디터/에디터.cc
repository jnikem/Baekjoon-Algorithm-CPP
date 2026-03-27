#include <iostream>
#include <string>

using namespace std;

const int MX = 600005;
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
                    erase(cursor);
                    cursor = pre[cursor];
                }
                break;
            case 'P':
                char add;
                cin >> add;
                insert(cursor, add);
                cursor = nxt[cursor];
                break;
        }
    }
    traversal();
    
    return 0;
}