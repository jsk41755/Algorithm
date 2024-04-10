#include <iostream>
using namespace std;

int n;
int arr[1001] = {0, 1, 3};

void dp() {
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + 2 * arr[i - 2]) % 10007;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp();

    cout << arr[n];

    return 0;
}
