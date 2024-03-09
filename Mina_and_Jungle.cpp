#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>

using namespace std;


/*
1 -2 0 4 5 6
6 5 4 3 2 1
5 1 0 0 6 3
1 2 5 8 4 6
9 8 0 1 5 6
Answer: 10;

1 0 0 4 5 6
6 5 4 -2 2 1
5 1 0 0 6 3
1 2 5 8 4 6
9 8 0 -1 5 6
Answer: Impossible;
*/

int n, m;
const int N = 1e3 + 5;
char grid[N][N];
bool visited[N][N];

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && grid[i][j] != 0;
}

vector<pi> direction = { { -1, -1 }, {-1, 1}, {1, -1}, {1, 1} };


void bfs(int s1, int s2) {

    queue<pi> q;
    q.push({ s1, s2 });

    visited[s1][s2] = true;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (auto [i, j] : direction) {
            int si = p.first + i;
            int sj = p.second + j;

            if (isValid(si, sj) && !visited[si][sj]) {
                visited[si][sj] = true;
                q.push({ si, sj });
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        pi start, end;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == -1) {
                    start = { i, j };
                }
                if (grid[i][j] == -2) {
                    end = { i, j };
                }
            }
        }

        memset(visited, false, sizeof(visited));
        bfs(start.first, start.second);
        if (visited[end.first][end.second]) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }

    }
    return 0;
}