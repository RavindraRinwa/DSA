#include <bits/stdc++.h>
using namespace std;

int randomize_partition(vector<int> &a, int l, int r)
{
    // Randomly pick a pivot and place it at the end
    int pivot_index = l + rand() % (r - l + 1);
    swap(a[pivot_index], a[r]);

    int ptr1 = l - 1;
    for (int i = l; i < r; i++)
    {
        if (a[i] < a[r])
        {
            ptr1++;
            swap(a[ptr1], a[i]);
        }
    }
    // Place pivot in the correct position
    swap(a[ptr1 + 1], a[r]);
    return ptr1 + 1;
}

int randomize_select(vector<int> &a, int l, int r, int i)
{
    // Check for valid input
    if (i < 1 || i > (r - l + 1))
    {
        throw invalid_argument("Index out of bounds");
    }

    if (l == r)
    {
        return a[l];
    }

    int q = randomize_partition(a, l, r);
    int k = q - l + 1;

    if (i == k)
    {
        return a[q];
    }
    else if (i < k)
    {
        return randomize_select(a, l, q - 1, i);
    }
    else
    {
        return randomize_select(a, q + 1, r, i - k);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> call_duration(n);
    int maxId = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> call_duration[i];
        if (call_duration[maxId] < call_duration[i])
        {
            maxId = i;
        }
    }
    vector<int> freq(call_duration[maxId] + 1);
    for (auto it : call_duration)
    {
        freq[it]++;
    }
    int leastFreq = 0;
    int mostFreq = 0;
    for (int i = 0; i < freq.size(); i += 2)
    {
        int pairMin, pairMax;
        if (freq[i] > freq[i + 1])
        {
            pairMax = i;
            pairMin = i + 1;
        }
        else
        {
            pairMax = i + 1;
            pairMin = i;
        }
        if (freq[pairMax] > freq[mostFreq])
        {
            mostFreq = pairMax;
        }
        if (freq[pairMin] < freq[leastFreq])
        {
            leastFreq = pairMin;
        }
    }
    cout << "most freq:" << mostFreq << " " << "least freq:" << leastFreq << "\n";
    // b
    cout << "i th most freq:";
    int x;
    cin >> x;
    cout << (randomize_select(freq, 0, freq.size() - 1, x)) << "\n";
}