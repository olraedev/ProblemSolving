#include <iostream>
using namespace std;

int N, M;
string str;
string findWord = "I";
int cnt;

void solve()
{
	int start = 0;

	while (1)
	{
		int idx = str.find(findWord, start);

		if (idx == -1) break;

		cnt++;
		start = idx + 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M >> str;

	for (int i = 0; i < N; i++)
		findWord += "OI";

	solve();

	cout << cnt << "\n";

	return 0;
}