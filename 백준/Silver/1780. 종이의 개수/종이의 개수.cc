#include<iostream>
using namespace std;

int arr[3000][3000];
int n;

int mi, ze, on;

void dc(int x, int y, int num) {
    int z = 0, o = 0, t = 0;

    for (int i = y; i < y + num; i++) {
        for (int j = x; j < x + num; j++) {
            if (arr[i][j] == -1) z++;
            else if (arr[i][j] == 0) o++;
            else t++;
        }
    }

    if ((z > 0 && o > 0) || (z > 0 && t > 0) || (o > 0 && t > 0)) {
        int half = num / 3;
        dc(x, y, half);
        dc(x + half, y, half);
        dc(x + half * 2, y, half);
        dc(x, y + half, half);
        dc(x + half, y + half, half);
        dc(x + half * 2, y + half, half);
        dc(x, y + half * 2, half);
        dc(x + half, y + half * 2, half);
        dc(x + half * 2, y + half * 2, half);
    }
    else if (z > 0 && o == 0 && t == 0) {
        mi++;
    }
    else if (z == 0 && o > 0 && t == 0) {
        ze++;
    }
    else {
        on++;
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

    dc(0, 0, n);

    cout << mi << "\n" << ze << "\n" << on;

    return 0;
}
