#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000];
int prefix[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    
    prefix[0] = arr[0];
    int sum = prefix[0];
    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
        sum += prefix[i];
    }
    
    cout << sum << "\n";
    return 0;
}