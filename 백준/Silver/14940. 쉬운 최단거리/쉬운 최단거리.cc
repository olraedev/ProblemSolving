#include <iostream>
#include <queue>
using namespace std;

int N, M;
struct Coord {
    int y, x;
};
int MAP[1001][1001];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int visited[1001][1001];
int cnt[1001][1001];
Coord start;
queue<Coord> q;

void bfs()
{
    q.push(start);
    cnt[start.y][start.x] = 0;
    visited[start.y][start.x] = 1;

    while(!q.empty()) {
        Coord now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (MAP[ny][nx] == 0) continue;
            if (visited[ny][nx] == 1) continue;

            visited[ny][nx] = 1;
            cnt[ny][nx] = cnt[now.y][now.x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2) start = {i, j};
        }
    
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 0) cout << "0 ";
            else if (visited[i][j] == 0 && cnt[i][j] == 0)
                cout << "-1 ";
            else cout << cnt[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}