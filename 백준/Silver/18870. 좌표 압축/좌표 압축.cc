#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int idx, num;
};
int N;
vector<Node> v;
int ans[1000001];

bool comp(Node a, Node b) {
    if (a.num < b.num) return true;
    return false;
}

void solve() {
    int before = v[0].num;
    int cnt = 0;
    
    for (int i = 1; i < N; i++) {
        if (before == v[i].num) {
            ans[v[i].idx] = cnt;
        } else {
            cnt++;
            ans[v[i].idx] = cnt;
        }
        before = v[i].num;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back({i, num});
    }

    sort(v.begin(), v.end(), comp);
    solve();

    for (int i = 0; i < N; i++) 
        cout << ans[i] << " ";

    return 0;
}