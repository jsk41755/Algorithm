#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPrime[1100001] = { false, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 2; i <= 1100000; i++) {
        if (!isPrime[i]) {
            for (int j = i * 2; j <= 1100000; j += i) {
                isPrime[j] = true;
            }
        }
    }

    if (n == 1) {
        cout << 2;
        return 0;
    }

    while (1) {
        if (isPrime[n]) {
            n++;
            continue;
        }

        int num = n;

        int num_original = n;
        int num_rev = 0;
        while (num > 0) {
            num_rev = num_rev * 10 + num % 10;
            num /= 10;
        }

        if (num_original == num_rev) {
            cout << num_rev;
            return 0;
        }

        n++;
    }


    return 0;
}