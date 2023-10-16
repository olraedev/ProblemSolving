#include <iostream>
#include <algorithm>
using namespace std;

int dp[50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        int mini = 21e8;
        for (int j = 1; j*j <= i; j++) {
            int tmp = i - j * j;
            mini = min(mini, dp[tmp]);
        }
        dp[i] = mini + 1;
    }

    cout << dp[N] << "\n";

    return 0;
}