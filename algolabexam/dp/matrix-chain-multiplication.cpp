#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> memo;
int matrixChainMultiplication(vector<int> &p, int l, int r)
{
    if (l + 1 == r)
    {
        return 0;
    }
    if (memo[l][r] != -1)
    {
        return memo[l][r];
    }
    int minop = 1e9;
    for (int i = l + 1; i < r; i++)
    {
        minop = min(matrixChainMultiplication(p, l, i) + matrixChainMultiplication(p, i, r) + p[l] * p[i] * p[r], minop);
    }
    return memo[l][r] = minop;
}

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    memo.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "minimum number of op:" << matrixChainMultiplication(p, 0, n - 1) << "\n";
}