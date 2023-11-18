#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int> person;
int maxTime = -21e8;

void input()
{
    person.clear();
    maxTime = -21e8;

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        maxTime = max(maxTime, n);
        person.push_back(n);
    }
}

string solve() 
{
    sort(person.begin(), person.end());

    int cnt = 0;
    int idx = 0;
    for(int time = 0; time <= maxTime; time++)
    {
        if (time != 0 && time % M == 0) cnt += K;
        if (time == person[idx]) {
            if (cnt == 0) return "Impossible";
            cnt--;
            idx++;
        }
    }
    return "Possible";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        input();
        cout << "#" << t << " " << solve() << "\n";
    }

    return 0;
}