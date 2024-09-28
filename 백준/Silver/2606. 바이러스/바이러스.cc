#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[101];

int Find(int x) {
	if (arr[x] == x) return x;
	return arr[x] = Find(arr[x]);
}

void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA < rootB) arr[rootA] = rootB;
	else arr[rootB] = rootA;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int num;

	cin >> n >> num;


	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;

		int rootA = Find(a);
		int rootB = Find(b);

		if (rootA > rootB) arr[rootA] = rootB;
		else arr[rootB] = rootA;
	}

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (Find(arr[i]) == 1) {
			cnt++;
		}
	}

	cout << cnt;


	return 0;
}