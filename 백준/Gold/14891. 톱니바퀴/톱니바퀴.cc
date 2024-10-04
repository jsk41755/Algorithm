#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

vector<string> gears(4);

void rotate(int idx, int dir) {
    if (dir == 1) {
        gears[idx] = gears[idx].back() + gears[idx].substr(0, 7);
    }
    else {
        gears[idx] = gears[idx].substr(1, 7) + gears[idx][0];
    }
}

void rotate_gears(int idx, int dir, vector<int>& rotation) {
    rotation[idx] = dir;

    for (int i = idx - 1; i >= 0; i--) {
        if (gears[i][2] != gears[i + 1][6]) {
            rotation[i] = -rotation[i + 1];
        }
        else break;
    }

    for (int i = idx + 1; i < 4; i++) {
        if (gears[i][6] != gears[i - 1][2]) {
            rotation[i] = -rotation[i - 1];
        }
        else break;
    }

    for (int i = 0; i < 4; i++) {
        if (rotation[i] != 0) {
            rotate(i, rotation[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> gears[0] >> gears[1] >> gears[2] >> gears[3];
    cin >> k;

    while (k--) {
        int idx, dir;
        cin >> idx >> dir;
        idx--;

        vector<int>  rotation(4, 0);
        rotate_gears(idx, dir, rotation);
    }

    int score = 0;
    if (gears[0][0] == '1') score += 1;
    if (gears[1][0] == '1') score += 2;
    if (gears[2][0] == '1') score += 4;
    if (gears[3][0] == '1') score += 8;

    cout << score;

    return 0;
}
