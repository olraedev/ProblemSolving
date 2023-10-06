#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int MAP[2][100001];
int dp[2][100001];

void input()
{
	memset(dp, 0, sizeof(dp));
	cin >> N;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];
}

void solve()
{
	dp[0][0] = MAP[0][0];
	dp[1][0] = MAP[1][0];
	dp[0][1] = MAP[0][1] + dp[1][0];
	dp[1][1] = MAP[1][1] + dp[0][0];

	for (int j = 2; j < N; j++)
	{
		dp[0][j] = max(MAP[0][j] + dp[0][j - 2], max(MAP[0][j] + dp[1][j - 2], MAP[0][j] + dp[1][j - 1]));
		dp[1][j] = max(MAP[1][j] + dp[1][j - 2], max(MAP[1][j] + dp[0][j - 2], MAP[1][j] + dp[0][j - 1]));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		input();
		solve();
		cout << max(dp[0][N - 1], dp[1][N - 1]) << "\n";
	}

	return 0;
}