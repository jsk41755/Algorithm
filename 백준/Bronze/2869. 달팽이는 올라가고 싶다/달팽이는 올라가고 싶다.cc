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

    int a, b, v;
    cin >> a >> b >> v;

    int cnt = 1;
    int load = 0;

    load = (v - b - 1) / (a - b) + 1;

    cout << load;

    return 0;
}
