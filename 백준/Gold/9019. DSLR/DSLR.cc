#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node {
    int num;
    string how;
};
char ch[] = {'D', 'S', 'L', 'R'};
int A, B;
int visited[10000];
queue<Node> q;
string ans;

void init() {
    cin >> A >> B;
    ans = "";
    memset(visited, 0, sizeof(visited));
    while(!q.empty()) q.pop();
}

int change(int num, char tmp) {
    if (tmp == 'D') {
        if (num * 2 > 9999) return num * 2 % 10000;
        return num * 2;
    }
    if (tmp == 'S') {
        if (num == 0) return 9999;
        return num - 1;
    }
    if (tmp == 'L') {
        return (num % 1000) * 10 + (num / 1000);
    }
    if (tmp == 'R') {
        return (num % 10) * 1000 + (num / 10);
    }
}

void solve() {
    q.push({A, ""});
    visited[A] = 1;

    while(!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            char tmp = ch[i];

            int result = change(now.num, tmp);
            
            if (visited[result] == 1) continue;
            if (result == B) {
                ans = now.how + tmp;
                return;
            }
            visited[result] = 1;
            q.push({result, now.how + tmp});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        init();
        solve();
        cout << ans << "\n";
    }

    return 0;
}