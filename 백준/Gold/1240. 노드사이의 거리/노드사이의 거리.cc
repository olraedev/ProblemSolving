#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int MAP[1001][1001];
bool visited[1001];

void dfs(int now, int end, int sum) {
    if (now == end) {
        cout << sum << "\n";
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (MAP[now][i] == 0) continue;
        if (visited[i]) continue;
        
        visited[i] = true;
        dfs(i, end, sum + MAP[now][i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N - 1; i++) {
        int from, to, cost;
        
        cin >> from >> to >> cost;
        MAP[from][to] = cost;
        MAP[to][from] = cost;
    }
    
    for (int i = 0; i < M; i++) {
        int from, to;
        
        cin >> from >> to;
        
        memset(visited, false, sizeof(visited));
        visited[from] = true;
        dfs(from, to, 0);
    }
    
    
    return 0;
}
