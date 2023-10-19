#include <iostream>
using namespace std;

struct Node {
    int zeroCnt;
    int oneCnt;
};
int N;
Node dp[41];

void solve()
{
    dp[0] = {1, 0};
    dp[1] = {0, 1};

    for (int i = 2; i <= 40; i++)
        dp[i] = {dp[i - 1].zeroCnt + dp[i - 2].zeroCnt, dp[i - 1].oneCnt + dp[i - 2].oneCnt};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;

    solve();

    for (int t = 1; t <= tc; t++) {
        cin >> N;

        cout << dp[N].zeroCnt << " " << dp[N].oneCnt << "\n";
    }

    return 0;
}