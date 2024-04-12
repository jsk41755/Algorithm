#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> arr;
long long test[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    long long pl = 3000000001;

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            long long pl2 = arr[i] + arr[l] + arr[r];


            if (abs(pl2) < pl) {
                pl = abs(pl2);
                test[0] = arr[i];
                test[1] = arr[l];
                test[2] = arr[r];
            }

            if (pl2 < 0) l++;
            else r--;
        }
    }

    cout << test[0] << " " << test[1] << " " << test[2];

    return 0;
}