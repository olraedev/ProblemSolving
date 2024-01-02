/*
    자신 + 위 + 왼쪽 - 대각선
*/
#include <iostream>
using namespace std;

int N, M;
int MAP[1025][1025];
int prefix[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            prefix[i][j] = MAP[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j -1];
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 -1] + prefix[x1 - 1][y1 -1];

        cout << sum << "\n";
    }

    return 0;
}