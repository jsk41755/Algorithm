#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int st = 1;
    int en = 1;

    vector<int> v;

    while (st <= en && en <=100000) {
        if (en * en - st * st == n) {
            v.push_back(en);
            st++;
        }
        else if (en * en - st * st > n) {
            st++;
        }
        else {
            en++;
        }

    }

    if (v.empty()) {
        cout << "-1";
        return 0;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}
