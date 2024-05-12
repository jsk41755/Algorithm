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

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}
