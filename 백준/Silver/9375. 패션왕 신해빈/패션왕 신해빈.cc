#include <iostream>
#include <unordered_map>
using namespace std;

int N;
unordered_map<string, int> um;
int ans;

void input()
{
	ans = 0;
	um.clear();

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string cloth, kind;
		cin >> cloth >> kind;

		um[kind]++;
	}
}

void solve()
{
	int sum = 0;
	int ex = 1;

	if (um.size() == 1)
	{
		for (auto cloth : um)
			sum += cloth.second;

		cout << sum << "\n";
		return;
	}

	for (auto cloth : um) {
		ex *= cloth.second + 1;
	}
	cout << ex - 1 << "\n";
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
	}

	return 0;
}