#include <iostream>
using namespace std;

int nums[100001];
int prefix[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> nums[i];
	
	prefix[1] = nums[1];

	for (int i = 2; i <= N; i++)
		prefix[i] = prefix[i - 1] + nums[i];

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << prefix[end] - prefix[start - 1] << "\n";
	}

	return 0;
}