#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> MAP[100001];
bool visited[100001];
int parent[100001];

void dfs(int now) {
    visited[now] = true;
    for (int i = 0; i < MAP[now].size(); i++) {
        int next = MAP[now][i];
        if (visited[next]) continue;

        parent[next] = now;
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int from, to;
        cin >> from >> to;

        MAP[from].push_back(to);
        MAP[to].push_back(from);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}