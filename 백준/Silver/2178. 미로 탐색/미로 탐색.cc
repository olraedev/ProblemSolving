#include <iostream>
#include <queue>
using namespace std;

int n, m;
string map[110];
int used[110][110];
queue<pair<int, int>> q;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main()
{
	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}

	used[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == n - 1 && x == m - 1)
		{
			cout << used[y][x];
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (used[ny][nx] != 0) continue;
			if (map[ny][nx] == '0') continue;

			used[ny][nx] = used[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	return 0;
}