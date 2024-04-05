#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int a, b, cost;
};

int N;
int temp[201][201];
priority_queue<Node> existRoad;
priority_queue<Node> newRoad;
int arr[201];
int answer;
int newRoadCount = 0;
vector<Node> newRoads;

bool operator<(Node b, Node a) {
    if (a.cost < b.cost) return true;
    return false;
}

void input() {
    cin >> N;   

    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> temp[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (temp[i][j] < 0) { existRoad.push({i, j, temp[i][j] * -1}); }
            if (0 < temp[i][j]) { newRoad.push({i, j, temp[i][j]}); }
        }
    }
}

int Find(int node) {
    if (arr[node] == node) return node;
    return arr[node] = Find(arr[node]);
} 

void Union(int a, int b) {
    int parentsA = Find(a);
    int parentsB = Find(b);

    arr[parentsB] = parentsA;
}

void solve() {
    for (int i = 1; i <= N; i++) { arr[i] = i; }

    while(!existRoad.empty()) {
        Node now = existRoad.top();
        existRoad.pop();

        Union(now.a, now.b);
        
        answer += now.cost;
    }

    while(!newRoad.empty()) {
        Node now = newRoad.top();
        newRoad.pop();

        if (Find(now.a) == Find(now.b)) continue;

        Union(now.a, now.b);

        newRoadCount++;
        answer += now.cost;
        newRoads.push_back({now.a, now.b});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    input();
    solve();

    cout << answer << " " << newRoadCount << "\n";
    for (int i = 0; i < newRoads.size(); i++) {
        cout << newRoads[i].a << " " << newRoads[i].b << "\n";
    }
}