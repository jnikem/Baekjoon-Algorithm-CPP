#include <iostream>
#include <string>

using namespace std;

const int MX = 5005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int i) {
    dat[unused] = i;
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

    int arr[5005];
    int N, K;
    cin >> N >> K;

    int cursor = 0;

    for (int i = 0; i < N; i++) {
        insert(cursor, i+1);
        cursor = nxt[cursor];
    }

    nxt[cursor] = nxt[0];
    pre[nxt[0]] = cursor;
    cursor = 0;

    cout << "<";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) cursor = nxt[cursor];
        erase(cursor);
        cout << dat[cursor];
        if (i != N-1) cout << ", ";
    }
    cout << ">";
    return 0;
}