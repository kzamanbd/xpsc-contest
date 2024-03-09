#include <bits/stdc++.h>
#define pi pair<int,int>

using namespace std;

class Compare {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second || (a.second == b.second && a.first < b.first);
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int query;
    cin >> query;
    map<int, int> freq;
    priority_queue<pi, vector<pi>, Compare> pq;

    while (query--) {
        int action;
        cin >> action;
        if (action == 1) {
            int x;
            cin >> x;
            freq[x]++;
            pq.push({ x, freq[x] });
        }
        else {
            if (pq.empty()) {
                cout << "empty" << '\n';
            }
            else {
                while (!pq.empty() && freq[pq.top().first] != pq.top().second) {
                    pq.pop();
                }

                if (!pq.empty()) {
                    int top = pq.top().first;
                    cout << top << '\n';
                    freq[top] = 0;
                }
                else {
                    cout << "empty" << '\n';
                }
            }
        }
    }
    return 0;
}