#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int arr[1001][1001];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int one = 0, zero = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) zero++;
            else one++;
        }
    }

    if (one % 2 == 1 || zero % 2 == 1) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int ax = j + dx[k];
                int ay = i + dy[k];
                if (ax >= 0 && ax < m && ay >= 0 && ay < n) {
                    if (arr[ay][ax] == arr[i][j]) {
                        cout << 1;
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}
