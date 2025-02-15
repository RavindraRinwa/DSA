#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> pt(n);
    vector<int> wt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pt[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> wt[j];
    }
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], pt[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << dp[n][W] << '\n';
}