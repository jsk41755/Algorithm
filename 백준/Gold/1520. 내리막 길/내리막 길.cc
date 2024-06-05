#include<iostream>
#include<vector>
using namespace std;
int arr[500][500];
int visit[500][500];
int n, m;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int dfs(int x, int y) {
    if (x == n - 1 and y == m - 1) return 1;
    if (visit[x][y] == -1) {
        visit[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int xx = dx[i] + x;
            int yy = dy[i] + y;
            if (xx >= 0 and xx < n and yy >= 0 and yy < m) {
                if (arr[xx][yy] < arr[x][y])
                    visit[x][y] += dfs(xx, yy);
            }
        }
    }
    return visit[x][y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            visit[i][j] = -1;
        }
    }

    cout << dfs(0, 0) << endl;
    return 0;
}