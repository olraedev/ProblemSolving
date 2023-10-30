#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int arr[100001];
int prefix[100001];

int solve() {
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    int start = 0;
    int end = 1;
    int mini = 21e8;
    while(1) {
        if (end > N || start > end) {
            if (mini == 21e8) return 0;
            return mini;
        }

        if (prefix[end] - prefix[start] >= S) {
            mini = min(mini, end - start);
            start++;
        } else end++;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cout << solve() << "\n";

    return 0;
}