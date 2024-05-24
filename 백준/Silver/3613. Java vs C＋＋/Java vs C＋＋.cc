#include <iostream>
#include <queue>
using namespace std;

string str;
queue<char> q;

bool isJava() {
    for (int i = 0; i < str.size(); i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            return true;
        }
    }
    return false;
}

bool isCpp() {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '_') {
            if (str[i + 1] == '_') {
                cout << "Error!\n";
                exit(0);
            }
            return true;
        }
    }
    return false;
}

void javaToCpp() {
    while (!q.empty()) {
        char now = q.front();
        q.pop();
        
        if ('a' <= now && now <= 'z') cout << now;
        else cout << '_' << char(now + 32);
    }
    cout << "\n";
}

void cppToJava() {
    while (!q.empty()) {
        char now = q.front();
        q.pop();
        
        if (now == '_') {
            char next = q.front();
            q.pop();
            
            cout << char(next - 32);
        } else cout << now;
    }
    cout << "\n";
}

void solve() {
    bool java = isJava();
    bool cpp = isCpp();
    
    if (str[0] == '_' || str[str.size() - 1] == '_' ||
        ('A' <= str[0] && str[0] <= 'Z') || (java && cpp)) {
        cout << "Error!\n";
        return;
    }
    if (java) javaToCpp();
    if (cpp) cppToJava();
    if (!java && !cpp) cout << str << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str;
    
    for (int i = 0; i < str.size(); i++) {
        q.push(str[i]);
    }
    
    solve();
}
