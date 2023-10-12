#include <iostream>
using namespace std;

int N;
int MAP[128][128];
int blue, white;

void solve(int y, int x, int size)
{
	bool cut = false;
	int first = MAP[y][x];

	for (int i = y; i < y + size; i++)
		for (int j = x; j < x + size; j++) {
			if (first != MAP[i][j]) {
				cut = true;
				break;
			}
		}

	if (cut) {
		solve(y, x, size / 2);
		solve(y, x + size / 2, size / 2);
		solve(y + size / 2, x, size / 2);
		solve(y + size / 2, x + size / 2, size / 2);
	}
	else {
		if (first == 1) blue++;
		else white++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];

	solve(0, 0, N);

	cout << white << "\n" << blue << "\n";

	return 0;
}