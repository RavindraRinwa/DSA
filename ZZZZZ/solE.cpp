#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k > max(m, n) || k < (max(n - m, m - n))) {
        cout << -1 << "\n";
        return;
    }
    int tn = n, tm = m;
    string ans = "";
    if (m >= n) {
        for (int i = 0; i < k; i++) {
            ans += "1";
            m--;
        }
        while (n > 0 && m > 0) {
            ans += "01";
            n--, m--;
        }
        while (n > 0) {
            ans += "0";
            n--;
        }
        if (m > 0) {
            cout << -1 << "\n";
            return;
        }
    }
    else {
        for (int i = 0; i < k; i++) {
            ans += "0";
            n--;
        }
        while (n > 0 && m > 0) {
            ans += "10";
            n--, m--;
        }
        if (n > 0) {
            cout << -1 << "\n";
            return;
        }
        while (m > 0) {
            ans += "1";
            m--;
        }
    }
    int cnt = 1;
    for (int i = ans.length() - 1; i > 0; i--) {
        if (ans[i] != ans[i - 1]) {
            break;
        }
        cnt++;
    }
    if (cnt > k) {
        cout << -1 << "\n";
        return;
    }
    cout << ans << "\n";
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