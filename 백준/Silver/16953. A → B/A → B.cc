#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

ll A, B;
ll mini = 21e8;

void dfs(ll lev, ll num)
{
	if (num == B)
	{
		mini = min(mini, lev);
		return;
	}

	string str = to_string(num) + "1";
	ll n = stol(str);

	if (num * 2 <= B)
		dfs(lev + 1, num * 2);
	if (n <= B)
		dfs(lev + 1, n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> A >> B;

	dfs(1, A);
	if (mini == 21e8) cout << "-1\n";
	else cout << mini << "\n";

	return 0;
}