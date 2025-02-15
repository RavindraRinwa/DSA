#include <bits/stdc++.h>
using namespace std;


void solve() {
	string s;
	cin >> s;
	string t = "";
	for (int i = 0; i < s.length() - 2; i++) {
		t += s[i];
	}
	t += "i";
	cout << t << "\n";
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