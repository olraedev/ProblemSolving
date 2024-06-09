#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info {
    int to, cost;
};

int N, M;
vector<Info> MAP[1001];
priority_queue<Info> pq;
int route[1001];
long long minCost[1001];
int start, fin;
vector<int> result;

bool operator<(Info b, Info a) {
    if (a.cost < b.cost) return true;
    return false;
}

void input() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        
        MAP[start].push_back({ end, cost });
    }
    
    cin >> start >> fin;
}

void solve() {
    
    for (int i = 1; i <= N; i++) minCost[i] = 21e8 / 2;
    minCost[start] = 0;
    pq.push({ start, 0 });
    
    while(!pq.empty()) {
        Info now = pq.top();
        pq.pop();
        
        if (minCost[now.to] < now.cost) continue;
        
        for (int i = 0; i < MAP[now.to].size(); i++) {
            int next = MAP[now.to][i].to;
            int nextCost = MAP[now.to][i].cost + now.cost;
            
            if (minCost[next] <= nextCost) continue;
            
            minCost[next] = nextCost;
            route[next] = now.to;
            pq.push({ next, nextCost });
        }
    }
}

void output() {
    int now = fin;
    result.push_back(now);
    
    while (now != start) {
        result.push_back(route[now]);
        now = route[now];
    }
    
    cout << minCost[fin] << "\n";
    cout << result.size() << "\n";
    
    for (int i = int(result.size() - 1); i >= 0; i--) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solve();
    output();
    
    return 0;
}
