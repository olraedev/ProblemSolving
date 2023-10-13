#include <iostream>
#include <algorithm>
using namespace std;

int N;
long M;
int tree[1000000];
int maxi = -21e8;
long long ans;
int got = 21e8;

void solve()
{
	int bottom = 1;
	int top = maxi;

	while (1)
	{
		if (bottom > top) break;

		int mid = (top + bottom) / 2;
		long long cnt = 0;

		for (int i = 0; i < N; i++)
		{
			if (tree[i] <= mid) continue;
			cnt += tree[i] - mid;
		}

		if (M > cnt) {
			top = mid - 1;
		}
		else {
			bottom = mid + 1;

			if (got > cnt - M) {
				got = cnt - M;
				ans = mid;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		maxi = max(maxi, tree[i]);
	}

	solve();
	cout << ans << "\n";

	return 0;
}