#include<iostream>
using namespace std;

int arr[500][500];
int sol = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, b;

    cin >> n >> m >> b;

    int nMin = 999999999;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

	for (int e = 0; e <= 256; e++) {
		int x = 0; //build
		int y = 0; //remove
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > e) {
					y += arr[i][j] - e;
				}
				else if (arr[i][j] < e) {
					x += e - arr[i][j];
				}
			}
		}
		if (y + b >= x) {
			int time = y * 2 + x;
			if (nMin >= time) {
				nMin = time;
				sol = e;
			}
		}
	}

	cout << nMin << " " << sol;

    return 0;
}