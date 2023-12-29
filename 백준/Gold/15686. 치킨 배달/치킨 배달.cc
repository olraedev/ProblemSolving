#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Coord {
    int y, x;
};
struct Info
{
    int y, x;
    bool state;
};
int N, M;
vector<Coord> house;
vector<Info> chicken;
int result = 21e8;

void find() {
    int sum = 0;

    for (int i = 0; i < house.size(); i++) {
        int houseDist = 21e8;
        for (int j = 0; j < chicken.size(); j++) {
            if (chicken[j].state == false) continue;
            
            int dist = abs(house[i].y - chicken[j].y) + abs(house[i].x - chicken[j].x);
            houseDist = min(houseDist, dist);
        }

        sum += houseDist;
    }

    result = min(result, sum);
}

void dfs(int lev, int idx, int cnt) {
    if (lev == cnt) {
        find();
        return;
    }

    for (int i = idx + 1; i < chicken.size(); i++) {
        chicken[i].state = true;
        dfs(lev + 1, i, cnt);
        chicken[i].state = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int value;
            cin >> value;

            if (value == 1) house.push_back({i, j});
            if (value == 2) chicken.push_back({i, j, false});
        }
    }

    for (int i = 1; i <= M; i++) {
        dfs(0, -1, i);
    }

    cout << result << "\n";

    return 0;
}