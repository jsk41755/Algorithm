#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[17][17];
bool isVisit[17][17] = { false, };

int dx[3] = { 1, 1, 0 };
int dy[3] = { 0, 1, 1 };

int cnt = 0;

void dfs(int y, int x, int dir) {
    if (y == n - 1 && x == n - 1) {
        cnt++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];

        if (ax >= 0 && ax < n && ay >= 0 && ay < n) {
            if (!isVisit[ay][ax]) {
                if (dir == 0) {
                    if (i == 0 && arr[ay][ax] != 1) {
                        isVisit[ay][ax] = true;
                        dfs(ay, ax, i);
                        isVisit[ay][ax] = false;
                    }
                    else if (i == 1 && arr[ay][ax] != 1 && arr[ay][ax - 1] != 1 && arr[ay - 1][ax] != 1 && !isVisit[ay - 1][ax] && !isVisit[ay][ax - 1]) {
                        isVisit[ay][ax] = true;
                        isVisit[ay - 1][ax] = true;
                        isVisit[ay][ax - 1] = true;
                        dfs(ay, ax, i);
                        isVisit[ay][ax] = false;
                        isVisit[ay - 1][ax] = false;
                        isVisit[ay][ax - 1] = false;
                    }
                } 
                else if (dir == 2) {
                    if (i == 2 && arr[ay][ax] != 1) {
                        isVisit[ay][ax] = true;
                        dfs(ay, ax, i);
                        isVisit[ay][ax] = false;
                    }
                    else if (i == 1 && arr[ay][ax] != 1 && arr[ay][ax - 1] != 1 && arr[ay - 1][ax] != 1 && !isVisit[ay - 1][ax] && !isVisit[ay][ax - 1]) {
                        isVisit[ay][ax] = true;
                        isVisit[ay - 1][ax] = true;
                        isVisit[ay][ax - 1] = true;
                        dfs(ay, ax, i);
                        isVisit[ay][ax] = false;
                        isVisit[ay - 1][ax] = false;
                        isVisit[ay][ax - 1] = false;
                    }
                }
                else {
                    if (i == 2 && arr[ay][ax] != 1) {
                        isVisit[ay][ax] = true;
                        dfs(ay, ax, i);
                        isVisit[ay][ax] = false;
                    }
                    else if (i == 1 && arr[ay][ax] != 1 && arr[ay][ax - 1] != 1 && arr[ay - 1][ax] != 1 && !isVisit[ay - 1][ax] && !isVisit[ay][ax - 1]) {
                        isVisit[ay][ax] = true;
                        isVisit[ay - 1][ax] = true;
                        isVisit[ay][ax - 1] = true;
                        dfs(ay, ax, i);
                        isVisit[ay][ax] = false;
                        isVisit[ay - 1][ax] = false;
                        isVisit[ay][ax - 1] = false;
                    }
                    else if (i == 0 && arr[ay][ax] != 1) {
                        isVisit[ay][ax] = true;
                        dfs(ay, ax, i);
                        isVisit[ay][ax] = false;
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    isVisit[0][0] = true;
    isVisit[0][1] = true;

    dfs(0, 1, 0);

    cout << cnt;

    return 0;
}