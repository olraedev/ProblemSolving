#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int MAP[10][10];
int used[10][10];
int maxi = 0;

bool check(int y, int x) {
    for (int i = 0; i < y; i++) {
        int a = x - (y - i);
        int b = x + (y - i);

        if (a >= 0 && used[i][a] == 1) return false;
        if (b < N && used[i][b] == 1) return false;
    }

    return true;
}

void whiteDfs(int ny, int nx, int cnt) {
    maxi = max(maxi, cnt);

    for (int y = ny; y < N; y++) {
        for (int x = nx; x < N; x+=2) {
            if (used[y][x] == 1) continue;
            if (MAP[y][x] == 0) continue;
            if (!check(y, x)) continue;

            used[y][x] = 1;
            whiteDfs(y, x, cnt + 1);
            used[y][x] = 0;
        }
        nx = (y + 1) % 2;
    }
}

void blackDfs(int ny, int nx, int cnt) {
    maxi = max(maxi, cnt);

    for (int y = ny; y < N; y++) {
        for (int x = nx; x < N; x+=2) {
            if (used[y][x] == 1) continue;
            if (MAP[y][x] == 0) continue;
            if (!check(y, x)) continue;

            used[y][x] = 1;
            blackDfs(y, x, cnt + 1);
            used[y][x] = 0;
        }
        nx = (y + 2) % 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> MAP[i][j];
    
    int ans = 0;
    
    whiteDfs(0, 0, 0);
    ans += maxi;
    
    memset(used, 0, sizeof(used));
    maxi = 0;
    blackDfs(0, 1, 0);
    ans += maxi;
    
    cout << ans << "\n";

    return 0;
}