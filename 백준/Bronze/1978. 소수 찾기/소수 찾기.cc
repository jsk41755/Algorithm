#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int cnt = 0;

    int j;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        for (j = 2; j < num; j++) {
            if (num % j == 0) break;
        }
        if (j == num) cnt++;
    }

    cout << cnt;

    return 0;
}
