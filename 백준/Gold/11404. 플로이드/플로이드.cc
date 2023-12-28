#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

int N, M;
int MAP[101][101];

void input() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) MAP[i][j] = 0;
            else MAP[i][j] = INF;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        MAP[a][b] = min(MAP[a][b], c);
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    input();

    for(int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                MAP[i][j] = min(MAP[i][j], MAP[i][k] + MAP[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (MAP[i][j] == INF) {
                cout << 0 << " ";
            } else cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}