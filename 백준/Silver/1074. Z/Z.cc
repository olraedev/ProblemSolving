#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int len;
long cnt = 0;
bool fin = false;

void partition(int y, int x, int size)
{
	if (y == r && x == c)
	{
		cout << cnt << "\n";
		return;
	}

	if (r < y + size && r >= y && c < x + size && c >= x)
	{
		partition(y, x, size / 2);
		partition(y, x + size / 2, size / 2);
		partition(y + size / 2, x, size / 2);
		partition(y + size / 2, x + size / 2, size / 2);
	} 
	else {
		cnt += size * size;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N >> r >> c;
	len = pow(2, N);

	partition(0, 0, len);

	return 0;
}