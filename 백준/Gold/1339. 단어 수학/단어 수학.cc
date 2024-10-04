#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int arr[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> s;
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        string a;
        cin >> a;
        s.push_back(a);

        for (int j = 0; j < a.size(); j++) {
            int ten = 1;
            for (int k = 0; k < a.size() - j - 1; k++) {
                ten *= 10;
            }
            arr[a[j] - 'A'] += ten;
        }
    }

    vector<int> weights;
    for (int i = 0; i < 26; i++) {
        if (arr[i] > 0) {
            weights.push_back(arr[i]);
        }
    }

    sort(weights.rbegin(), weights.rend());

    int result = 0;
    int number = 9;
    for (int i = 0; i < weights.size(); i++) {
        result += weights[i] * number;
        number--;
    }

    cout << result;

    return 0;
}
