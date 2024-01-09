#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Coord {
    int y, x;
};
int N, M;
int MAP[101][101];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
bool visited[101][101] = {false,};

bool isFinish() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 1) return false;
        }
    }
    return true;
}

void checkOutAir() {
    queue<Coord> q;
    
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()) {
        Coord now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visited[ny][nx]) continue;
            if (MAP[ny][nx] == 1) continue;

            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

void melt() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int cnt = 0;
            if (MAP[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                    if (visited[ny][nx] == true) cnt++;
                }
            }
            if (cnt >= 2) MAP[i][j] = 0;
        }
    }
}

int solve() {
    int time = 0;
    queue<Coord> q;

    while(!isFinish()) {
        memset(visited, false, sizeof(visited));
        checkOutAir();
        melt();
        time++;
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }

    cout << solve() << "\n";

    return 0;
}