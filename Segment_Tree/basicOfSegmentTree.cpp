#include <bits/stdc++.h>
using namespace std;

class SGTree
{
    vector<int> seg;
    vector<int> lazy;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        if (r < low || high < l)
            return INT_MAX;

        // complete overlap
        // l low high r
        if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    // range update by  lazy propogation
    void rangeUpdate(int ind, int low, int high, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] = (high - low + 1) * lazy[ind];
                lazy[2 * ind + 2] = (high - low + 1) * lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (low > r || high < l || low > high)
        {
            return;
        }
        // complete overlap
        if (l <= low && high <= r)
        {
            seg[ind] += ((high - low) * val);
            if (low != high)
            {
                lazy[2 * ind + 1] = (high - low + 1) * lazy[ind];
                lazy[2 * ind + 2] = (high - low + 1) * lazy[ind];
            }
            return;
        }
        int mid = (low + high) / 2;
        rangeUpdate(2 * ind + 1, low, mid, l, r, val);
        rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind] + 2;
    }
    int queryLazy(int ind, int low, int high, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] = (high - low + 1) * lazy[ind];
                lazy[2 * ind + 2] = (high - low + 1) * lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (l > high || r < low || low > high)
        {
            return 0;
        }
        // complete overlap
        if (low >= l && r >= high)
        {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        int left = queryLazy(2 * ind + 1, low, mid, l, r, val);
        int right = queryLazy(2 * ind + 2, mid + 1, high, l, r, val);
        return left + right;
    }
};

int main()
{
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    SGTree sgt(n);
    sgt.build(0, 0, n - 1, arr);

    cout << "Min in range [1, 4]: " << sgt.query(0, 0, n - 1, 1, 4) << endl; // Output should be 2
    sgt.update(0, 0, n - 1, 3, 0);
    cout << "After update, min in range [1, 4]: " << sgt.query(0, 0, n - 1, 1, 4) << endl; // Output should be 0

    return 0;
}
