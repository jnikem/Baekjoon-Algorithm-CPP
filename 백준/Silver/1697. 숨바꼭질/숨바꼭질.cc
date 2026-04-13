#include <bits/stdc++.h>
using namespace std;

int dist[100005];
int N, K;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    fill(dist, dist+100001, -1);
    dist[N] = 0;
    queue<int> BFS;
    BFS.push(N);
    
        while(dist[K] == -1){
            int cur = BFS.front(); BFS.pop();
            for (int nxt : {cur-1, cur+1, 2*cur}){
                if(nxt < 0 || nxt > 100000) continue;
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur]+1;
                BFS.push(nxt);
            }
        }

    cout << dist[K];
    
    return 0;
}