#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
string map[1001];
int result[1001][1001];
bool visited[1001][1001];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (map[y][x] == '1') continue;
            if (visited[y][x]) continue;
            
            vector<pair<int, int>> wall;
            queue<pair<int, int>> q;
            int cnt = 1;
            
            q.push({y, x});
            visited[y][x] = true;
            
            while(!q.empty()) {
                pair<int, int> now = q.front();
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int ny = now.first + dy[i];
                    int nx = now.second + dx[i];
                    
                    if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                    if (visited[ny][nx]) continue;
                    
                    if (map[ny][nx] == '1') wall.push_back({ny, nx});
                    else {
                        q.push({ny, nx});
                        cnt++;
                    }
                    visited[ny][nx] = true;
                }
            }
            
            for (int i = 0; i < wall.size(); i++) {
                result[wall[i].first][wall[i].second] += cnt;
                visited[wall[i].first][wall[i].second] = false;
            }
        }
    }
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (map[y][x] == '0') cout << 0;
            else cout << (result[y][x] + 1) % 10;
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
    
    solve();
    
    return 0;
}
