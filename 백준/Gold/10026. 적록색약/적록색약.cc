#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int arr[101][101];
bool isVisit[101][101];

int aarr[101][101];
bool aisVisit[101][101];

int cnt = 0;
int acnt = 0;
int n;

void dfs(int y, int x, int color) {
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];

        if (ax >= 0 && ax < n && ay >= 0 && ay < n) {
            if (!isVisit[ay][ax] && color == arr[ay][ax]) {
                isVisit[ay][ax] = true;
                dfs(ay, ax, color);
            }
        }
    }
}

void adfs(int y, int x, int color) {
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];

        if (ax >= 0 && ax < n && ay >= 0 && ay < n) {
            if (!aisVisit[ay][ax] && color == aarr[ay][ax]) {
                aisVisit[ay][ax] = true;
                adfs(ay, ax, color);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;


    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'G') {
                aarr[i][j] = 'R';
            }
            else aarr[i][j] = s[j];

            arr[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!isVisit[i][j]) {
                isVisit[i][j] = true;
                dfs(i, j, arr[i][j]);
                cnt++;
            }

            if (!aisVisit[i][j]) {
                aisVisit[i][j] = true;
                adfs(i, j, aarr[i][j]);
                acnt++;
            }
        }
    }

    cout << cnt << " " << acnt;

    return 0;
}
