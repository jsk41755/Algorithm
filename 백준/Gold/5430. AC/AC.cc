#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string p;
        int n;
        vector<int> v;
        string x;

        cin >> p >> n >> x;
        string a = "";

        if (n == 0) {
            bool hasD = false;
            for (char cmd : p) {
                if (cmd == 'D') {
                    hasD = true;
                    break;
                }
            }
            if (hasD) {
                cout << "error\n";
            }
            else {
                cout << "[]\n";
            }
            continue;
        }

        for (int i = 1; i < x.size(); i++) {
            if (isdigit(x[i])) {
                a += x[i];
            }
            else if (x[i] == ',' || x[i] == ']') {
                if (!a.empty()) {
                    v.push_back(stoi(a));
                    a = "";
                }
            }
        }

        bool reverseFlag = false;
        int front = 0, back = n - 1;
        bool errorFlag = false;

        for (char cmd : p) {
            if (cmd == 'R') {
                reverseFlag = !reverseFlag;
            }
            else if (cmd == 'D') {
                if (front > back) {
                    errorFlag = true;
                    break;
                }
                if (reverseFlag) {
                    back--;
                }
                else {
                    front++;
                }
            }
        }

        if (errorFlag) {
            cout << "error\n";
        }
        else {
            cout << "[";
            if (front <= back) {
                if (reverseFlag) {
                    for (int i = back; i >= front; i--) {
                        cout << v[i];
                        if (i != front) cout << ",";
                    }
                }
                else {
                    for (int i = front; i <= back; i++) {
                        cout << v[i];
                        if (i != back) cout << ",";
                    }
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}
