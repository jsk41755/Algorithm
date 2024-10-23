#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int arr[500001];
map<int, int> ma;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ma[num]++;
    }

    int m;
    cin >> m;


    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (ma[num] > 0) {
            arr[i] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
