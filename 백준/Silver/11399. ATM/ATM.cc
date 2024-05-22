#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    int arr[1001];
    sort(v.begin(), v.end());
    arr[0] = v[0];
    int sol = arr[0];
    for (int i = 1; i < n; i++) {
        arr[i] = v[i] + arr[i-1];
        sol += arr[i];
    }

   cout << sol;

    return 0;
}
