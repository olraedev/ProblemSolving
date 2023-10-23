#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int visited[8];

void dfs(int lev, vector<int> route) {
    if (lev == M) {
        for(int i = 0; i < route.size(); i++) {
            cout << route[i] << " ";
        }
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 1 || tmp == v[i]) continue;
        
        visited[i] = 1;
        route.push_back(v[i]);
        tmp = v[i];
        dfs(lev + 1, route);
        visited[i] = 0;
        route.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());
    vector<int> route;
    dfs(0, route);

    return 0;
}