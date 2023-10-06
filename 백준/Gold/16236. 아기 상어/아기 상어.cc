#include <iostream>
#include <queue>
using namespace std;

struct Coord {
	int y, x;
};
struct Info {
	int y, x;
	double time;
};
int N;
int MAP[21][21];
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
Coord shark;
Info fish = { 21, 21, 21e8 };
queue<Info> q;
int weight = 2;
bool eat = false;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] == 9) {
				MAP[i][j] = 0;
				shark = { i, j };
			}
		}
}

void bfs()
{
	int visited[21][21] = { 0, };

	q.push({shark.y, shark.x, 0});
	visited[shark.y][shark.x] = 1;
	
	while (!q.empty())
	{
		Info now = q.front();
		q.pop();

		if (MAP[now.y][now.x] > 0 && weight > MAP[now.y][now.x] && fish.time >= now.time)
		{
			if (fish.y > now.y || (fish.y == now.y && fish.x > now.x))
			{
				fish = { now.y, now.x, now.time };
				eat = true;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited[ny][nx] == 1) continue;
			if (weight < MAP[ny][nx]) continue;

			visited[ny][nx] = 1;
			q.push({ ny, nx, now.time + 1 });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	input();
	
	int time = 0;
	int cnt = 0;
	while (1)
	{
		bfs();

		if (eat) {

			// 상어가 먹자
			shark = { fish.y, fish.x };
			MAP[fish.y][fish.x] = 0;
			// 먹은 개수 늘리기
			cnt++;
			// 시간 추가
			time += fish.time;
			// 무게 증가 요인
			if (weight == cnt) {
				weight++;
				cnt = 0;
			}

			// 초기화
			fish = { 21, 21, 21e8 };
			eat = false;
		}
		else break;
	}

	cout << time << "\n";

	return 0;
}