#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rion[100002][3];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    rion[1][0] = 1;
    rion[1][1] = 1;
    rion[1][2] = 1;

    for (int i = 2; i <= n; i++) {
        rion[i][0] = (rion[i - 1][0] + rion[i - 1][1] + rion[i - 1][2]) % 9901;
        rion[i][1] = (rion[i - 1][0] + rion[i - 1][2]) % 9901;
        rion[i][2] = (rion[i - 1][0] + rion[i - 1][1]) % 9901;
    }

    cout << (rion[n][0] + rion[n][1] + rion[n][2]) % 9901;


    return 0;
}
