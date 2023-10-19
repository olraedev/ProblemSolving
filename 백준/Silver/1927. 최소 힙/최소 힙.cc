#include <iostream>
#include <queue>
using namespace std;

struct Node {
    long long num;
};
int N;
priority_queue<Node> q;

bool operator<(Node b, Node a) {
    if (a.num < b.num) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;

        if (num == 0) {
            if (q.size() == 0) cout << "0\n";
            else {
                cout << q.top().num << "\n";
                q.pop();
            }
        } else {
            q.push({num});
        }
    }

    return 0;
}