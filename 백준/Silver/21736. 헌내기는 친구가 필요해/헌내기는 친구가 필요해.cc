#include <iostream>
#include <queue>
using namespace std;

int N, M;
string MAP[601];
int visited[601][601];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;
int cnt = 0;

void solve()
{
	visited[q.front().first][q.front().second] = 1;

	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] == 1) continue;
			if (MAP[ny][nx] == 'X') continue;
			if (MAP[ny][nx] == 'P') cnt++;

			visited[ny][nx] = 1;
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

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> MAP[i];
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] == 'I')
				q.push({i, j});
		}
	}
	solve();
	if (cnt == 0) cout << "TT\n";
	else cout << cnt << "\n";

	return 0;
}