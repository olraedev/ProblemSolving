#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

int N, M;
unordered_map<string, int> um1;
unordered_map<int, string> um2;

void input()
{
    int cnt = 1;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        um1[name] = cnt;
        um2[cnt] = name;

        cnt++;
    }
}

void solve()
{
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;

        if ('1' <= str[0] && str[0] <= '9') {
            cout << um2[stoi(str)] << "\n";
        } else {
            cout << um1[str] << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}