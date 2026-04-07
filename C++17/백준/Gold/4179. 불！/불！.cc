#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define X first
#define Y second

string board[1005];
int fire_dist[1005][1005];
int j_dist[1005][1005];
int R, C;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    queue<pair<int, int>> Q_f;
    queue<pair<int, int>> Q_j;

    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            fire_dist[i][j] = -1;
            j_dist[i][j] = -1;
            if (board[i][j] == 'F') {
                Q_f.push({i, j});
                fire_dist[i][j] = 0;
            }
            if (board[i][j] == 'J') {
                Q_j.push({i, j});
                j_dist[i][j] = 0;
            }
        }
    }

    while (!Q_f.empty()) {
        pair<int,int> cur = Q_f.front();
        Q_f.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (fire_dist[nx][ny] != -1 || board[nx][ny] == '#') continue;
            fire_dist[nx][ny] = fire_dist[cur.X][cur.Y] + 1;
            Q_f.push({nx, ny});
        }
    }

    while (!Q_j.empty()) {
        pair<int,int> cur = Q_j.front();
        Q_j.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << j_dist[cur.X][cur.Y] + 1;
                return 0;
            }

            if (j_dist[nx][ny] != -1 || board[nx][ny] == '#') continue;
            
            if (fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= j_dist[cur.X][cur.Y] + 1) continue;

            j_dist[nx][ny] = j_dist[cur.X][cur.Y] + 1;
            Q_j.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}