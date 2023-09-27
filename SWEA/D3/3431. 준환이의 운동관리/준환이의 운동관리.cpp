#include <iostream>
using namespace std;

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
		int L, U, X, ret = 0;
		cin >> L >> U >> X;

		if (L >= X) ret = L - X;
		else if (U < X) ret = -1;

		cout << "#" << t << " " << ret << "\n";
	}

	return 0;
}