#include <bits/stdc++.h>
using namespace std;

void printSubSequence(vector<vector<string>> path, int i, int j, string s1)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (path[i][j] == "digonal")
    {
        printSubSequence(path, i - 1, j - 1, s1);
        cout << s1[i - 1];
    }
    if (path[i][j] == "upper")
    {
        printSubSequence(path, i - 1, j, s1);
    }
    if (path[i][j] == "right")
    {
        printSubSequence(path, i, j - 1, s1);
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<string>> path(n + 1, vector<string>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = "digonal";
            }
            else
            {
                if (dp[i - 1][j] >= dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = "upper";
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    path[i][j] = "right";
                }
            }
        }
    }
    cout << "The longest subsequence is length of:" << dp[n][m] << "\n";
    printSubSequence(path, n, m, s1);
}