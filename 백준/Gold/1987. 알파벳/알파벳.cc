#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[21][21];
int alphabet[26];
bool isVisit[21][21];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0, 0,1,-1 };

int r, c;

int ans = 1;

void dfs(int x, int y, int cnt) {
    bool flag = false;

    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];

        if (ax >= 0 && ax < c && ay >= 0 && ay < r && !isVisit[ay][ax] && alphabet[arr[ay][ax]-'A'] == 0) {
            isVisit[ay][ax] = true;
            alphabet[arr[ay][ax] - 'A']++;
            dfs(ax, ay, cnt + 1);
            isVisit[ay][ax] = false;
            alphabet[arr[ay][ax] - 'A']--;
        }
        else {
            ans = max(ans, cnt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < c; j++) {
            arr[i][j] = s[j];
        }
    }

    alphabet[arr[0][0] - 'A']++;
    isVisit[0][0] = true;

    dfs(0, 0, 1);

    cout << ans;

    return 0;
}
