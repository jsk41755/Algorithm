#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n; 
    cin >> n;

    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v[i] = num;
    }
    sort(v.begin(), v.end());

    int m = v[0];
    int cnt = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        if (m - 1 > 0) {
            m--;
        }
        else {
            cnt++;
            m = v[i+1];
        }

       //cout << m << "\n";
    }

    if (m - 1 >= 0) cnt++;

    cout << cnt;

    return 0;
}
