#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 101

int N;
int MAP[MAX][MAX];
int ans[MAX][MAX];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void init()
{
	memset(MAP, 0, sizeof(MAP));
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans[i][j] = 21e8;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;

		for (int j = 0; j < N; j++)
			MAP[i][j] = tmp[j] - '0';
	}
}

void solve()
{
	queue<pair<int, int>> q;

	ans[0][0] = 0;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (ans[ny][nx] <= ans[y][x] + MAP[ny][nx]) continue;

			ans[ny][nx] = ans[y][x] + MAP[ny][nx];
			q.push({ ny, nx });
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
		solve();
		cout << "#" << t << " " << ans[N - 1][N - 1] << "\n";
	}

	return 0;
}