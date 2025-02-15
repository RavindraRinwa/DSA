#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
	int n;
	cin >> n;
	vector<int>a(n);
	map<int, int>mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}

	for (auto &[num, count] : mp) {
		if (count >= 2) {
			cout << "1\n" << num << "\n";
			return;
		}
	}

	cout << -1 << "\n";

}



int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif


	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}