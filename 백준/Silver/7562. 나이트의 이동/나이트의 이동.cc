#include <iostream>

#include <queue>

#include <utility>

#include <algorithm>

using namespace std;

#define X first

#define Y second

int dist[1005][1005];

int T, I, knight_X, knight_Y, target_X, target_Y;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(void) {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >> T;

    while(T--){

        queue<pair<int,int>> Q;

        cin >> I;

        

        for (int i = 0; i < I; i++){

            for (int j = 0; j < I; j++) dist[i][j] = -1;

        }

        

        cin >> knight_X >> knight_Y;

        cin >> target_X >> target_Y;

        

        Q.push({knight_X, knight_Y});

        dist[knight_X][knight_Y] = 0;

        

    while(dist[target_X][target_Y] == -1){

        pair<int,int> cur = Q.front(); 

        Q.pop();

        for (int dir = 0; dir < 8; dir++){

            int nx = cur.X + dx[dir];

            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;

            if(dist[nx][ny] != -1) continue;

            if (dist[cur.X][cur.Y] > -1)

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;

            Q.push({nx, ny});

             }

        }    

    cout << dist[target_X][target_Y] << "\n";

    }    

    return 0;

}