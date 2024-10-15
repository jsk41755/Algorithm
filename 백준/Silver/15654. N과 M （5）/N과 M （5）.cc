#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	ans.resize(v.size(), 0);

	sort(v.begin(), v.end());

	do {
		bool flag = false;
		for (int i = 0; i < m; i++) {
			if (ans[i] == v[i]) flag = true;
			else flag = false;

			if (!flag) break;
		}

		if (!flag) {
			for (int i = 0; i < m; i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
		}

		for (int i = 0; i < m; i++) {
			ans[i] = v[i];
		}


	} while (next_permutation(v.begin(), v.end()));


	return 0;
}