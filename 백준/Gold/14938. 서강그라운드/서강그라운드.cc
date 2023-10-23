#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> items;
int MAP[101][101];
int maxi = -21e8;

void input() {
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        int amount;
        cin >> amount;
        items.push_back(amount);
    }
    for (int i = 0; i < R; i++) {
        int start, fin, dist;
        cin >> start >> fin >> dist;

        MAP[start-1][fin-1] = dist;
        MAP[fin-1][start-1] = dist;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (i != j && MAP[i][j] == 0) MAP[i][j] = 16;
        }
}

void solve() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (MAP[i][k] + MAP[k][j] < MAP[i][j])
                    MAP[i][j] = MAP[i][k] + MAP[k][j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (MAP[i][j] <= M)
                cnt += items[j];
        }
        maxi = max(maxi, cnt);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    input();
    solve();
    cout << maxi << "\n";

    return 0;
}