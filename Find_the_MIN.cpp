#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int query;
    cin >> query;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (query--) {
        int action;
        cin >> action;
        if (action == 1) {
            int x;
            cin >> x;
            pq.push(x);
        }
        else {
            if (!pq.empty()) {
                int top = pq.top();
                while (!pq.empty() && pq.top() == top) {
                    pq.pop();
                }
                cout << top << "\n";
            }
            else {
                cout << "empty" << '\n';
            }
        }
    }
    return 0;
}