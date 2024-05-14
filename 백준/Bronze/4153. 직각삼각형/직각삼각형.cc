#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1) {
        int a, b, c;

        cin >> a >> b >> c;

        if (a == 0) break;

        if ((a * a) + (b * b) == c * c) {
            cout << "right" << "\n";
        }
        else if ((b * b) + (c * c) == a * a) {
            cout << "right" << "\n";
        }
        else if ((c * c) + (a * a) == b * b) {
            cout << "right" << "\n";
        }
        else {
            cout << "wrong" << "\n";
        }
    }

    return 0;
}
