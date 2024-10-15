#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v(100001,vector<int>());
int arr[100001] = { 0, };
int n;

void rec(int leaf) {
	for (int i = 0; i < v[leaf].size(); i++) {
		if (arr[v[leaf][i]] == 0) {
			arr[v[leaf][i]] = leaf;
			rec(v[leaf][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int f, s;
		cin >> f >> s;

		v[f].push_back(s);
		v[s].push_back(f);
	}

	arr[1] = 1;
	rec(1);

	for (int i = 2; i <= n; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}