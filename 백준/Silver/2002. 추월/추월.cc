#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    map<string, int> m;
    vector<string> inp;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        m.insert({ s, i });
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        inp.push_back(s);
    }

    for (int i = 0; i < inp.size(); i++) {
        for (int j = i + 1; j < inp.size(); j++) {
            if (m[inp[i]] > m[inp[j]]) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;


    return 0;
}
