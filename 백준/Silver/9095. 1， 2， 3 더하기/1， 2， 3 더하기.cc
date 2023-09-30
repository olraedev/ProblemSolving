#include <iostream>
using namespace std;

int dp[12];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int tc;
	cin >> tc;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 11; i++)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

	for (int t = 1; t <= tc; t++)
	{
		int N;
		cin >> N;

		cout << dp[N] << "\n";
	}

	return 0;
}