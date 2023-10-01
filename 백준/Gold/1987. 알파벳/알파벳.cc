#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
int dat[150];
string MAP[21];
int used[21][21];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int maxi = -21e8;

void dfs(int lev, int y, int x)
{
	maxi = max(maxi, lev);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
		if (used[ny][nx] == 1) continue;
		if (dat[MAP[ny][nx]] == 1) continue;

		used[ny][nx] = 1;
		dat[MAP[ny][nx]] = 1;

		dfs(lev + 1, ny, nx);

		used[ny][nx] = 0;
		dat[MAP[ny][nx]] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		cin >> MAP[i];

	used[0][0] = 1;
	dat[MAP[0][0]] = 1;
	dfs(1, 0, 0);
	cout << maxi << "\n";

	return 0;
}