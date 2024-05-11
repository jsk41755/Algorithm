#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int arr[100][100];
bool isVisit[100][100] = { false, };
bool isRain[100][100] = { false, };

int dx[4] = { 1,-1, 0, 0 };
int dy[4] = { 0,0, 1, -1 };


int cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int nMax = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] > nMax) {
                nMax = arr[i][j];
            }
        }
    }

    int rain = 0;

    while (rain < nMax) {
        int safe = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isVisit[i][j] || arr[i][j] > rain) continue;

                queue<pair<int, int>> q;
                isVisit[i][j] = true;
                q.push({ i, j });

                while (!q.empty()) {
                    int x = q.front().second;
                    int y = q.front().first;

                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int ax = dx[i] + x;
                        int ay = dy[i] + y;

                        if (ax >= 0 && ax < n && ay >= 0 && ay < n) {
                            if (!isVisit[ay][ax] && arr[ay][ax] <= rain) {
                                q.push({ ay, ax });
                                isVisit[ay][ax] = true;
                            }
                        }

                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isVisit[i][j] || isRain[i][j]) continue;

                queue<pair<int, int>> q;
                isRain[i][j] = true;
                q.push({ i, j });

                safe++;

                while (!q.empty()) {
                    int x = q.front().second;
                    int y = q.front().first;

                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int ax = dx[i] + x;
                        int ay = dy[i] + y;

                        if (ax >= 0 && ax < n && ay >= 0 && ay < n) {
                            if (!isRain[ay][ax] && !isVisit[ay][ax]) {
                                q.push({ ay, ax });
                                isRain[ay][ax] = true;
                            }
                        }

                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                isRain[i][j] = false;
            }
        }

        rain++;
        cnt = max(cnt, safe);
    }

    cout << cnt;



    return 0;
}
