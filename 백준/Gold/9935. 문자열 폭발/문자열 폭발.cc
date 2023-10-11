#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// freopen_s(new FILE*, "input.txt", "r", stdin);

	string str, boom;
	cin >> str >> boom;

	string temp = "";

	for (int i = 0; i < str.size(); i++)
	{
		temp += str[i];

		if (temp.length() < boom.length()) continue;

		bool state = true;
		if (temp[temp.length() - 1] == boom[boom.length() - 1])
		{
			for (int j = 0; j < boom.length(); j++)
			{
				if (temp[temp.length() - (boom.length() - j)] != boom[j])
				{
					state = false;
					break;
				}
			}

			if (state)
			{
				for (int j = 0; j < boom.length(); j++)
					temp.pop_back();
			}
		}
	}

	if (temp.length() == 0)
		cout << "FRULA\n";
	else
		cout << temp << "\n";
	
	return 0;
}