#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 401
int N, M;
vector<pair<int, int>> MAP[MAX];
int used[MAX];
bool back[MAX];
int mini;

void init()
{
	for (int i = 1; i < MAX; i++) MAP[i].clear();
	memset(back, false, sizeof(back));
	mini = 21e8;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;

		MAP[s].push_back({ e, c });
		back[e] = true;
	}
}

void dfs(int now, int sum, int start)
{
	used[now] = 1;

	for (int i = 0; i < MAP[now].size(); i++)
	{
		int next = MAP[now][i].first;
		int val = MAP[now][i].second;

		if (used[next] == 0) {
			if (mini > sum + val) dfs(next, sum + val, start);
		}
		else {
			if(next == start) mini = min(mini, sum + val);
		}
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
		init();
		for (int i = 1; i <= N; i++)
		{
			memset(used, 0, sizeof(used));
			if (back[i] == false) continue;

			dfs(i, 0, i);
		}
		if (mini == 21e8) cout << "#" << t << " -1\n";
		else cout << "#" << t << " " << mini << "\n";
	}

	return 0;
}