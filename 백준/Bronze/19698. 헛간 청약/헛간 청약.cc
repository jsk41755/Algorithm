#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, w, h, l;
	cin >> n >> w >> h >> l;

	w /= l;
	h /= l;

	if (n <= w * h) cout << n;
	else cout << w * h;

	return 0;
}