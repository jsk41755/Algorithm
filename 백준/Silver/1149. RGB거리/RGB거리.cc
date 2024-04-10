#include <iostream>
using namespace std;

int n;
int arr[1001][3];
int sol[1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for(int i=1; i<=n; i++) {
        sol[i][0] = min(sol[i-1][1], sol[i-1][2]) + arr[i][0];
        sol[i][1] = min(sol[i-1][0], sol[i-1][2]) + arr[i][1];
        sol[i][2] = min(sol[i-1][0], sol[i-1][1]) + arr[i][2];
    }


    cout << min(min(sol[n][0], sol[n][1]), sol[n][2]);

    return 0;
}
