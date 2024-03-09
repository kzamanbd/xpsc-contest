#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int row = n * 2 - 1;
    vector<int> num = { 1, 2, 0 };
    int index = 0;

    for (int i = 0; i < row; i++) {
        if (index == 3) index = 0;
        for (int j = 0; j < row; j++) {
            if (i == j) {
                cout << num[index];
            }
            else if (i + j == row - 1) {
                cout << num[index];
            }
            else {
                cout << " ";
            }

        }
        index++;
        cout << endl;
    }

    return 0;
}