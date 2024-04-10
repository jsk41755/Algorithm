#include <iostream>
using namespace std;

int n;
int arr[1025][1025];
int sol[1025][1025];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            sol[i][j] = sol[i-1][j] + sol[i][j-1] - sol[i-1][j-1] + arr[i][j];
        }
    }

    for(int i=1; i<=m; i++) {
        int x1, x2, y1, y2;
        int ans;

        cin >> x1 >> y1 >> x2 >> y2;

        ans = sol[x2][y2] - sol[x2][y1-1] - sol[x1-1][y2] + sol[x1-1][y1-1];
        cout << ans << "\n";
    }


    return 0;
}
