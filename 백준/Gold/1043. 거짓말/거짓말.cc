#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int human[51];
int riar[51];

vector<vector<int>> v;
vector<int> rv;

int Find(int i) {
    if (human[i] == i) return i;
    else return human[i] = Find(human[i]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    human[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    v.resize(m, vector<int>());

    int k;

    cin >> k;

    for (int i = 0; i < 51; i++) {
        human[i] = i;
        riar[i] = i;
    }

    if (k > 0) {
        int first;
        cin >> first;
        rv.push_back(first);

        for (int i = 1; i < k; i++) {
            int num;
            cin >> num;
            Union(first, num);
            rv.push_back(num);
        }
    }

    int cnt = 0;
    while (cnt < m) {
        int num;
        cin >> num;

        if (num > 0) {
            int first;
            cin >> first;

            v[cnt].push_back(first);

            for (int i = 1; i < num; i++) {
                int second;
                cin >> second;
                Union(first, second);
                v[cnt].push_back(second);
            }
        }
        cnt++;
    }


    cnt = 0;
    int ground = 0;

    while (cnt < m) {
        bool flag = false;

        for (int i = 0; i < v[cnt].size(); i++) {
            for (int j = 0; j < rv.size(); j++) {
                if (Find(rv[j]) == Find(v[cnt][i])) {
                    flag = true;
                }
            }
        }

        if (!flag) ground++;

        cnt++;
    }

    cout << ground;

    return 0;
}
