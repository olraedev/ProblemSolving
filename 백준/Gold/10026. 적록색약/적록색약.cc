#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int y, x;
};
int N;
string MAP[101];
int used[101][101];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void input()
{
	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;

		MAP[i] = row;
	}
}

void solve()
{
	// 적록색약 아닌 사람
	int cnt = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			if (used[y][x] == 0)
			{
				cnt++;
				queue<Node> q;
				q.push({ y, x });
				used[y][x] = 1;

				while (!q.empty())
				{
					Node now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int ny = now.y + dy[i];
						int nx = now.x + dx[i];

						if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
						if (used[ny][nx] == 1) continue;
						if (MAP[now.y][now.x] != MAP[ny][nx]) continue;

						used[ny][nx] = 1;
						q.push({ ny, nx });
					}
				}
			}
		}
	cout << cnt << " ";

	cnt = 0;
	memset(used, 0, sizeof(used));

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			if (used[y][x] == 0)
			{
				cnt++;
				queue<Node> q;
				q.push({ y, x });
				used[y][x] = 1;

				while (!q.empty())
				{
					Node now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++)
					{
						int ny = now.y + dy[i];
						int nx = now.x + dx[i];

						if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
						if (used[ny][nx] == 1) continue;
						if (MAP[now.y][now.x] == 'R' && MAP[ny][nx] == 'B') continue;
						if (MAP[now.y][now.x] == 'G' && MAP[ny][nx] == 'B') continue;
						if (MAP[now.y][now.x] == 'B' && MAP[now.y][now.x] != MAP[ny][nx]) continue;

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

	cin >> N;
	input();
	solve();

	return 0;
}