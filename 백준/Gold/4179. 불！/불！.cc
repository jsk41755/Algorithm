#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int r, c;

char arr[1001][1001];
bool visit[1001][1001] = { false, };
int matrix[1001][1001];

bool fvisit[1001][1001] = { false, };

int dx[4] = { 1,-1, 0,0 };
int dy[4] = { 0, 0, 1,-1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    queue<pair<int, int>> q;
    queue<pair<int, int>> f;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'J') {
                q.push({ i,j });
                visit[i][j] = true;
            }
            if (arr[i][j] == 'F') {
                f.push({ i,j });
                matrix[i][j] = -1;
                fvisit[i][j] = true;
            }
        }
    }

    int cnt = 1987654321;

    while (true) {
        int human = q.size();

        if (human == 0) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        for (int k = 0; k < human; k++) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            if (arr[y][x] == 'F') continue;

            for (int i = 0; i < 4; i++) {
                int ax = x + dx[i];
                int ay = y + dy[i];

                if (ax >= 0 && ax < c && ay >= 0 && ay < r) {
                    if (arr[ay][ax] != '#' && matrix[ay][ax] >= 0 && !visit[ay][ax] && arr[ay][ax] != 'F') {
                        visit[ay][ax] = true;
                        matrix[ay][ax] = matrix[y][x] + 1;
                        q.push({ ay,ax });
                        arr[ay][ax] = 'J';
                    }
                }
                else {
                    cnt = min(cnt, matrix[y][x] + 1);

                    cout << cnt;
                    return 0;
                }
            }
        }

        int fire = f.size();

        for (int i = 0; i < fire; i++) {
            int fx = f.front().second;
            int fy = f.front().first;
            f.pop();

            for (int j = 0; j < 4; j++) {
                int ax = fx + dx[j];
                int ay = fy + dy[j];

                if (ax >= 0 && ax < c && ay >= 0 && ay < r) {
                    if (arr[ay][ax] != '#' && !fvisit[ay][ax]) {
                        matrix[ay][ax] = matrix[fy][fx] - 1;
                        f.push({ ay,ax });
                        fvisit[ay][ax] = true;
                        arr[ay][ax] = 'F';
                    }
                }
            }
        }
    }


    return 0;
}