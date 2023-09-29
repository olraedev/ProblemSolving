#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y, x;
	char state;
};
int N, M;
string MAP[51];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
queue<Node> q;

void input()
{
	while (!q.empty()) q.pop();
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> MAP[i];
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] != '?') q.push({ i, j, MAP[i][j] });
		}
	}
}

bool solve()
{
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (MAP[ny][nx] != '?') {
				if (now.state == MAP[ny][nx]) return false;
			} else
			{
				if (now.state == '#') MAP[ny][nx] = '.';
				else MAP[ny][nx] = '#';
				q.push({ ny, nx, MAP[ny][nx] });
			}
		}
	}

	return true;
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
		bool ans = solve();
		if (!ans) cout << "#" << t << " impossible\n";
		else cout << "#" << t << " possible\n";
	}

	return 0;
}