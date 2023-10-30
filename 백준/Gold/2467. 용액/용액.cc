#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    int start = 0;
    int end = N - 1;
    int mini = 21e8;
    pair<int, int> ans;
    
    while(start < end) {
        int temp = arr[end] + arr[start];
        if (mini > abs(temp - 0)) {
            mini = abs(temp - 0);
            ans = {arr[start], arr[end]};
        }
        if (temp < 0) start++;
        else end--;
    }

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}