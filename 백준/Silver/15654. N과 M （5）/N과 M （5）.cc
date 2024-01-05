#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int visited[8];

void dfs(int lev, vector<int> tmp) {
    if (lev == M) {
        for (int i = 0; i < tmp.size(); i++) {
            cout << tmp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        tmp.push_back(v[i]);
        dfs(lev + 1, tmp);
        tmp.pop_back();
        visited[i] = 0;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        v.push_back(n);
    }

    sort(v.begin(), v.end());

    vector<int> tmp;
    dfs(0, tmp);

    return 0;
}