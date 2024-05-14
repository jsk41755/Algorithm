#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int arr[20000001] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[num+10000000]++;
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cout << arr[num+10000000] << " ";
    }

    return 0;
}
