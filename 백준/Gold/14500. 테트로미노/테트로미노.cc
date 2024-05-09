#include<iostream>
using namespace std;

int arr[500][500];

int dx[4] = { 1,-1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool isVisit[500][500] = { false, };
int sol = 0;

int n, m;

void dfs(int y, int x, int cnt, int sum) {
    if (cnt == 3) {
        sol = max(sol, sum);

        return;
    }

    for (int i = 0; i < 4; i++) {
        int ax = dx[i] + x;
        int ay = dy[i] + y;

        if (ay >= 0 && ay < n && ax >= 0 && ax < m) {
            if (!isVisit[ay][ax]) {
                isVisit[ay][ax] = true;
                dfs(ay, ax, cnt + 1, sum + arr[ay][ax]);
                isVisit[ay][ax] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            isVisit[i][j] = true;
            dfs(i, j, 0, arr[i][j]);
            isVisit[i][j] = false;

            if (j + 2 < m && i + 1 < n) { // ㅜ
                sol = max(sol, (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]));
            }
            if (j + 1 < m && i + 1 < n && i - 1 >= 0) { // ㅏ
                sol = max(sol, (arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i - 1][j]));
            }
            if (j - 1 >= 0 && i + 1 < n && i - 1 >= 0) { // ㅓ
                sol = max(sol, (arr[i][j] + arr[i][j - 1] + arr[i + 1][j] + arr[i - 1][j]));
            }
            if (j + 2 < m && i - 1 >= 0) { // ㅗ
                sol = max(sol, (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1]));
            }
        }
    }

    cout << sol;

    return 0;
}