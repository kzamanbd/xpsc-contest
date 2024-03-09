#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if ((str[i] == '0' && str[i - 1] == '1') || (str[i] == '1' && str[i - 1] == '0')) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}