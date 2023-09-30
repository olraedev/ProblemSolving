#include <iostream>
using namespace std;

long long dp[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int tc;
	cin >> tc;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i - 5] + dp[i - 1];

	for (int t = 1; t <= tc; t++)
	{
		int N;
		cin >> N;

		cout << dp[N] << "\n";
	}

	return 0;
}