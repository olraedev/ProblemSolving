#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> timeTable;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int begin, end;
        cin >> begin >> end;

        timeTable.push_back({end, begin});
    }

    sort(timeTable.begin(), timeTable.end());

    int endTime = timeTable[0].first;
    int cnt = 1;

    for (int i = 1; i < N; i++) {
        if (endTime <= timeTable[i].second) {
            cnt++;
            endTime = timeTable[i].first;
        }
    }

    cout << cnt << "\n";

    return 0;
}