#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int start;
	int end;
};
int N, M;
vector<Node> ladder;
vector<Node> snake;
// 0: 주사위, 1: 사다리, 2: 뱀
int visited[3][101];

int solve()
{
	queue<pair<int, int>> q;

	visited[0][1] = 1;
	q.push({ 1, 0 });

	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		if (1 <= 100 - now.first && 100 - now.first <= 6)
			return now.second + 1;

		for (int i = 1; i <= 6; i++)
		{
			bool lad = false, sna = false;
			int next = now.first + i;
			int cnt = now.second;

			if (next > 100) continue;
			if (next == 100) return cnt + 1;
			if (visited[0][next] == 1) continue;

			for (int j = 0; j < N; j++)
			{
				if (next == ladder[j].start)
				{
					if (visited[1][ladder[j].end] == 1) continue;

					lad = true;
					visited[1][ladder[j].end] = 1;
					q.push({ ladder[j].end, cnt + 1 });
				}
			}

			if (lad) continue;
			
			for (int j = 0; j < M; j++)
			{
				if (next == snake[j].start)
				{
					if (visited[2][snake[j].end] == 1) continue;

					sna = true;
					visited[2][snake[j].end] = 1;
					q.push({ snake[j].end, cnt + 1 });
				}
			}

			if (sna) continue;
			
			visited[0][next] = 1;
			q.push({ next, cnt + 1 });
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
		int start, end;
		cin >> start >> end;
		ladder.push_back({ start, end });
	}
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		snake.push_back({ start, end });
	}
	cout << solve() << "\n";

	return 0;
}