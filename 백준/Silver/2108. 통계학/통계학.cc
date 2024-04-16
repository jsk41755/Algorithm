
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, input;
int a, b, c, d;
vector<int> v;
vector<pair<int, int>> numv;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2)
{

	if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
	return p1.second > p2.second;

}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v.push_back(input);
	}

	if (n == 1)
	{
		a = b = c = v[0];
		d = 0;

		cout << a << "\n" << b << "\n" << c << "\n" << d;
		return 0;
	}

	sort(v.begin(), v.end());

	// a
	for (int i = 0; i < n; i++)
	{
		a += v[i];
	}
	a = round((float)a / n);


	// b
	b = v[(n / 2)];

	// c
	for (int i = 0; i < v.size(); i++)
	{
		if (numv.empty())
		{
			numv.push_back({ v[i],1 });
			continue;
		}
		if (numv.back().first == v[i])
		{
			pair<int, int> _tmp = numv.back();
			_tmp.second++;
			numv.pop_back();
			numv.push_back(_tmp);
		}
		else
		{
			numv.push_back({ v[i],1 });
		}
	}

	sort(numv.begin(), numv.end(), comp);

	if (numv[0].second == numv[1].second ? (c = numv[1].first) : (c = numv[0].first));


	// d
	d = (v[n - 1]) - (v[0]);


	cout << a << "\n" << b << "\n" << c << "\n" << d;
	return 0;
}