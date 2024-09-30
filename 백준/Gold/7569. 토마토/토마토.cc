#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dz[6] = { 0, 0, 0, 0, 1,-1 };
int dx[6] = { 1,-1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1,-1, 0, 0 };

int arr[101][101][101];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, h;
    cin >> m >> n >> h;

    queue < pair<pair<int, int>, int>> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) q.push({ {i,j},k });
            }
        }
    }

    while (!q.empty()) {
        int z = q.front().first.first;
        int y = q.front().first.second;
        int x = q.front().second;

        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h) {
                if (arr[nz][ny][nx] == 0) {
                    arr[nz][ny][nx] = arr[z][y][x] + 1;
                    q.push({{nz, ny}, nx});
                }
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (arr[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }

                cnt = max(cnt, arr[i][j][k]);
            }
        }
    }

    cout << cnt - 1;

    return 0;
}
