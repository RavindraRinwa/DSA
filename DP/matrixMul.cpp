#include <bits/stdc++.h>
using namespace std;

int matrixMul(vector<int> &dim, int i, int j, vector<vector<int>> &memo)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    int res = INT_MAX;

    for (int k = i + 1; k < j; k++)
    {
        int cur = matrixMul(dim, i, k, memo) + matrixMul(dim, k, j, memo) + dim[i] * dim[k] * dim[j];
        res = min(res, cur);
    }

    return memo[i][j] = res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dim(n);

    for (int i = 0; i < n; i++)
    {
        cin >> dim[i];
    }

    vector<vector<int>> memo(n, vector<int>(n, -1));
    matrixMul(dim, 0, n - 1, memo);
}