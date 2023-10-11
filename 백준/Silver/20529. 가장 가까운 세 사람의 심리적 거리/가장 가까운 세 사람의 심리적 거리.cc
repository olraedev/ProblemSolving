#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int mini;
string MAP[100001];

void input()
{
	mini = 21e8;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> MAP[i];
}

void dfs(int level, int now, vector<int> v)
{
	if (level == 3)
	{
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			if (MAP[v[0]][i] != MAP[v[1]][i]) cnt++;
			if (MAP[v[1]][i] != MAP[v[2]][i]) cnt++;
			if (MAP[v[0]][i] != MAP[v[2]][i]) cnt++;
		}
		mini = min(mini, cnt);
		return;
	}

	for (int next = now + 1; next < N; next++)
	{
		v.push_back(next);
		dfs(level + 1, next, v);
		v.pop_back();
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
		
		if (N > 32)
		{
			cout << 0 << "\n";
			continue;
		}
		
		vector<int> v;
		dfs(0, -1, v);
		cout << mini << "\n";
	}

	return 0;
}