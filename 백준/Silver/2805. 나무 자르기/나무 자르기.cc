#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int tree = 0;

void bsearch(int start, int end) {
    if (start > end) return;

    int mid = (end + start) / 2;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int tmp = v[i] - mid;
        if (tmp > 0) sum += tmp;
    }

    if (sum >= m) {
        if (tree < mid) {
            tree = mid;
        }
        bsearch(mid + 1, end);
    }
    else {
        bsearch(start, mid - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int hMax = -1;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);

        if (hMax < num) hMax = num;
    }

    bsearch(0, hMax);

    cout << tree;

    return 0;
}
