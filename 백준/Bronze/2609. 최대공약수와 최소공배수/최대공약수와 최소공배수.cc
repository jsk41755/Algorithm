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

    int a, b;

    cin >> a >> b;

    int num1 = 0;
    int num2 = 0;

    if (a > b) num2 = b;
    else num2 = a;

    for (int i = 1; i <= num2; i++) {
        if (a % i == 0 && b % i == 0) {
            num1 = i;
        }
    }

    int numA = a / num1;
    int numB = b / num1;

    cout << num1 << "\n" << num1 * numA * numB;


    return 0;
}
