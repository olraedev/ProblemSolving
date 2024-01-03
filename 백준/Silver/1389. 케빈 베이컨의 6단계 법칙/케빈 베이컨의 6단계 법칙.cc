#include <iostream>
using namespace std;

int N, M;
int MAP[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        MAP[from][to] = 1;
        MAP[to][from] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && MAP[i][j] != 1) {
                MAP[i][j] = 10001;
            }
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (MAP[i][k] + MAP[k][j] < MAP[i][j]) {
                    MAP[i][j] = MAP[i][k] + MAP[k][j];
                }
            }
        }
    }

    int idx = 0;
    int mini = 21e8;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += MAP[i][j];
        }
        if (mini > sum) {
            mini = sum;
            idx = i;
        }
    }

    cout << idx << "\n";

    return 0;
}