#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> all_class;
priority_queue<int, vector<int>, greater<int>> time_table;

void solve() {
    time_table.push(all_class[0].second);
    
    for (int i = 1; i < N; i++) {
        time_table.push(all_class[i].second);
        
        if (time_table.top() <= all_class[i].first) {
            time_table.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        
        all_class.push_back({start, end});
    }
    
    sort(all_class.begin(), all_class.end());
    solve();
    cout << time_table.size() << "\n";
    
    return 0;
}
