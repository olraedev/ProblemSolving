#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, string> um;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string site, pw;
        cin >> site >> pw;

        um[site] = pw;
    }

    for (int i = 0; i < M; i++) {
        string site;
        cin >> site;

        cout << um[site] << "\n";
    }

    return 0;
}