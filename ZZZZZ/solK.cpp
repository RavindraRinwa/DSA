#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n;
	cin >> n;
	long long sum = 0;
	int minEle = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (i + j == n - 1) {
				minEle = min(minEle, x);
			}
			sum += x;
		}
	}
	cout << sum - minEle << "\n";
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif


	ios_base::sync_with_stdio(0);
	cin.tie(0);


	solve();

	return 0;
}