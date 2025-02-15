#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: Cost of multiplying one matrix is 0
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    // l is the chain length
    for (int l = 2; l < n; l++)
    {
        for (int i = 0; i < n - l; i++)
        {
            int j = i + l;
            dp[i][j] = 1e9;                 // Endpoint of the chain =
            for (int k = i + 1; k < j; k++) // Possible partition points
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + p[i] * p[k] * p[j]);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";
}
