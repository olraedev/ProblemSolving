#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	int cnt = 0;
	unordered_map<string, int> um;
	vector<string> v;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;

		um.insert({ name, i });
	}

	for (int i = 0; i < M; i++)
	{
		string name;
		cin >> name;

		if (um.count(name))
		{
			cnt++;
			v.push_back(name);
		}
	}

	sort(v.begin(), v.end());

	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	
	return 0;
}