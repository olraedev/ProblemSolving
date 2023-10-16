#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int n;
};
int N;
priority_queue<Node> pq;

bool operator<(Node b, Node a)
{
    if (a.n > b.n) return true;
    return false;
}

void solve()
{
    cin >> N;

    for (int n = 0; n < N; n++)
    {
        int num;
        cin >> num;

        if (num == 0) {
            if (pq.size() == 0) cout << "0\n";
            else {
                cout << pq.top().n << "\n";
                pq.pop();
            }
        } else {
            pq.push({num});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    solve();

    return 0;
}