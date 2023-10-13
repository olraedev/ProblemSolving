#include <iostream>
using namespace std;

int N, M, ans;
string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> M >> str;

	for (int i = 1; i < str.length(); i++)
	{
		int cnt = 0;
		if (str[i - 1] == 'I') {
			while (str[i] == 'O' && str[i + 1] == 'I') {
				i += 2;
				cnt++;
				if (cnt == N) {
					cnt--;
					ans++;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}