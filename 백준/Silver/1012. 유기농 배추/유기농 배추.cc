#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
	int y, x;
};
int N, M, K;
int MAP[51][51];
int used[51][51];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void init()
{
	memset(MAP, 0, sizeof(MAP));
	memset(used, 0, sizeof(used));
}

void input()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;

		MAP[y][x] = 1;
	}
}

void solve()
{
	int cnt = 0;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			if (MAP[y][x] == 1 && used[y][x] == 0)
			{
				queue<Node> q;
				q.push({ y, x });
				used[y][x] = 1;
				cnt++;
				
				while (!q.empty())
				{
					Node now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int ny = now.y + dy[i];
						int nx = now.x + dx[i];

						if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
						if (MAP[ny][nx] == 0 || used[ny][nx] == 1) continue;

						used[ny][nx] = 1;
						q.push({ ny, nx });
					}
				}
			}
		}

	cout << cnt << "\n";
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
		input();
		solve();
	}

	return 0;
}