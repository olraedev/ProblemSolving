#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Info {
    int h, y, x;
    int day;
};

int M, N, H;
int MAP[101][101][101];
int dh[] = {0, 0, 0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};
queue<Info> tomato;

void solve() {
    while(!tomato.empty()) {
        Info now = tomato.front();
        tomato.pop();

        for (int i = 0; i < 6; i++) {
            int nh = now.h + dh[i];
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (nh < 0 || nh >= H || ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (MAP[nh][ny][nx] != 0) continue;

            MAP[nh][ny][nx] = MAP[now.h][now.y][now.x] + 1;
            tomato.push({nh, ny, nx, now.day + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> MAP[i][y][x];
                if (MAP[i][y][x] == 1) tomato.push({i, y, x, 0});
            }
        }
    }

    solve();

    int day = -21e8;

    for (int i = 0; i < H; i++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (MAP[i][y][x] == 0) {
                    cout << -1;
                    return 0;
                }
                day = max(day, MAP[i][y][x]);
            }
        }
    }

    cout << day - 1;

    return 0;
}