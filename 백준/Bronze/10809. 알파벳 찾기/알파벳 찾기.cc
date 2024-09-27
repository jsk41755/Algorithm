#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> arr(26,-1);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if(arr[s[i] - 'a'] == -1)
		arr[s[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}