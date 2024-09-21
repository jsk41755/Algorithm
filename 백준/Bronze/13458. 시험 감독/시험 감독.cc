#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, b, c;

	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	cin >> b >> c;
	
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		v[i] -= b;
		cnt++;
	}

	for (int i = 0; i < n; i++) {
		if (v[i] > 0 && v[i] % c > 0) {
			cnt += v[i] / c + 1;
		}
		else if(v[i] > 0){
			cnt += v[i] / c;
		}
	}

	cout << cnt;


	return 0;
}