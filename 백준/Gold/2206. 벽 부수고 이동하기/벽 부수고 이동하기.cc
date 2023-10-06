#include <iostream>
#include <queue>
using namespace std;

// block = 0 -> 뿌심
// block = 1 -> 아직 안 뿌심
struct Node {
	int y, x;
	int block;
};
int N, M;
string MAP[1001];
int visited[1001][1001][2];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
queue<Node> q;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> MAP[i];
}

int solve()
{
	q.push({ 0, 0, 1 });
	visited[0][0][1] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		q.pop();

		if (now.y == N - 1 && now.x == M - 1) 
			return visited[now.y][now.x][now.block];

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			int block = now.block;

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (MAP[ny][nx] == '1' && block == 1)
			{
				q.push({ ny, nx, 0 });
				visited[ny][nx][0] = visited[now.y][now.x][block] + 1;
			}
			if (MAP[ny][nx] == '0' && visited[ny][nx][block] == 0)
			{
				q.push({ ny, nx, block });
				visited[ny][nx][block] = visited[now.y][now.x][block] + 1;
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	cout << solve() << "\n";

	return 0;
}