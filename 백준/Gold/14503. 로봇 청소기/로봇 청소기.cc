#include<iostream>
using namespace std;

int n, m;
int r, c, d;
int sol = 0;
int arr[50][50];

// 북, 동, 남, 서 순서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void one(int x, int y) {
    if (arr[x][y] == 0) {
        arr[x][y] = 2; // 청소한 위치를 2로 표시
        sol++;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    while (true) {
        // 1. 현재 위치 청소
        one(r, c);

        bool isClean = true;
        for (int i = 0; i < 4; i++) {
            int nd = (d + 3) % 4;
            int nx = r + dx[nd];
            int ny = c + dy[nd];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
                d = nd;
                r = nx;
                c = ny;
                isClean = false;
                break;
            }
            else {
                d = nd;
            }
        }

        if (isClean) {
            // 후진
            int back = (d + 2) % 4;
            int bx = r + dx[back];
            int by = c + dy[back];

            if (bx >= 0 && bx < n && by >= 0 && by < m && arr[bx][by] != 1) {
                r = bx;
                c = by;
            }
            else {
                break;
            }
        }
    }

    cout << sol;

    return 0;
}
