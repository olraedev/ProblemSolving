#include <iostream>
#include <queue>
using namespace std;

struct FireBall {
    int m, s, d;
    bool state;
};
int N, M, K;
queue<FireBall> MAP[51][51];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int tDir[] = {0, 2, 4, 6};
int fDir[] = {1, 3, 5, 7};

void move() {
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (MAP[y][x].empty()) continue;

            queue<FireBall> temp;

            while(!MAP[y][x].empty()) {
                FireBall now = MAP[y][x].front();
                MAP[y][x].pop();

                if (now.state) {
                    temp.push(now);
                    continue;
                }

                int move = now.s % N;
                int ny = y + (dy[now.d] * move);
                int nx = x + (dx[now.d] * move);

                if (ny <= 0) ny += N;
                if (nx <= 0) nx += N;
                if (ny > N) ny -= N;
                if (nx > N) nx -= N;

                MAP[ny][nx].push({now.m, now.s, now.d, true});
            }

            while(!temp.empty()) {
                FireBall now = temp.front();
                temp.pop();

                MAP[y][x].push(now);
            }
        }
    }
}

void merge() {
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (MAP[y][x].empty()) continue;

            if (MAP[y][x].size() == 1) {
                FireBall now = MAP[y][x].front();
                MAP[y][x].pop();

                MAP[y][x].push({now.m, now.s, now.d, false});
                continue;
            }

            int sumM = 0;
            int sumS = 0;
            int count = MAP[y][x].size();
            
            bool even = true;
            bool odd = true;

            while(!MAP[y][x].empty()) {
                FireBall now = MAP[y][x].front();
                MAP[y][x].pop();

                sumM += now.m;
                sumS += now.s;
                if(now.d % 2 == 0) odd = false;
                else even = false;
            }

            if (sumM / 5 == 0) continue;
            
            if (even || odd) {
                for (int i = 0; i < 4; i++) {
                    MAP[y][x].push({sumM / 5, sumS / count, tDir[i], false});
                }
            } else {
                for (int i = 0; i < 4; i++) {
                    MAP[y][x].push({sumM / 5, sumS / count, fDir[i], false});
                }
            }
        }
    }
}

void solve() {
    for (int k = 1; k <= K; k++) {
        move();
        merge();
    }
}

void print() {
    int sum = 0;

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            if (MAP[y][x].empty()) continue;

            while(!MAP[y][x].empty()) {
                FireBall now = MAP[y][x].front();
                MAP[y][x].pop();

                sum += now.m;
            }
        }
    }

    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int y, x, m, s, d;

        cin >> y >> x >> m >> s >> d;
        MAP[y][x].push({m, s, d, false});
    }

    solve();
    print();

    return 0;
}