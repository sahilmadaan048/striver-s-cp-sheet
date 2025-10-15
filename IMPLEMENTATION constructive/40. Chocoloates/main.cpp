// https://codeforces.com/problemset/problem/1139/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	long long ans = 0;
	int prev = INT_MAX;

	for (int i = n - 1; i >= 0; i--)
	{
		int take = min(a[i], prev - 1);
		if (take < 0)
			take = 0;
		ans += take;
		prev = take;
	}

	cout << ans << "\n";
	return 0;
}
