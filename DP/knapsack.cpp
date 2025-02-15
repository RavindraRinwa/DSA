#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &p, int i, int w, int n)
{
    if (w <= 0 || i >= n)
    {
        return 0;
    }

    if (wt[i] > w)
        return knapsack(wt, p, i + 1, w, n);

    return max(knapsack(wt, p, i + 1, w, n), knapsack(wt, p, i + 1, w - wt[i], n) + p[i]);
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> profit(n);
    vector<int> weight(n);

    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> weight[j];
    }

    cout << (knapsack(weight, profit, 0, w, n));
}