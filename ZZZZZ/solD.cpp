#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void solve() {
	int n;
	cin >> n;

	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		--a[i];
	}

	if (a[0] != 0 && a[0] != 1) {
		cout << "NO" << "\n";
		return;
	}

	if (a[n - 1] != 0 && a[n - 1] != 1) {
		cout << "NO" << "\n";
		return;
	}

	vector<int>invId(n);
	for (int i = 0; i < n; i++) {
		invId[a[i]] = i;
	}

	set<int>st;
	st.insert(0); st.insert(n - 1);

	multiset<int, greater<int>>maxLen;
	maxLen.insert(n - 1 - 1);

	for (int i = 2; i < n; i++) {
		int id = invId[i];
		int lb = *(--st.lower_bound(id));
		int ub = *(st.upper_bound(id));

		int d = min(id - lb, ub - id);
		int maxD = *maxLen.begin();
		maxLen.erase(maxLen.find(maxD));
		int reqD = (maxD + 1) / 2;

		if (d != reqD) {
			cout << "NO" << "\n";
			return;
		}
		if (maxD % 2 == 0) {
			maxLen.insert(maxD / 2);
			maxLen.insert(maxD / 2 - 1);
		}
		else {
			maxLen.insert(maxD / 2);
			maxLen.insert(maxD / 2);
		}
		st.insert(id);
	}
	cout << "YES" << "\n";
}



int main()
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