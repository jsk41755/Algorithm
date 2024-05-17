#include<iostream>
using namespace std;

int arr[128][128];
int n;

int white = 0, blue = 0;

void dc(int x, int y, int num) {
    int w = 0, b = 0;

    for (int i = y; i < y + num; i++) {
        for (int j = x; j < x + num; j++) {
            if (arr[i][j] == 0) w++;
            else b++;
        }
    }

    if (w > 0 && b > 0) {
        dc(x, y, num / 2);
        dc(x + num / 2, y, num / 2);
        dc(x, y + num / 2, num / 2);
        dc(x + num / 2, y + num / 2, num / 2);
    }
    else if (w > 0 && b == 0) {
        white++;
    }
    else {
        blue++;
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

    cout << white << "\n" << blue;

    return 0;
}
