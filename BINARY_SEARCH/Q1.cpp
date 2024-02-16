#include<iostream>
#include<vector>
using namespace std;

int main() {
    int arr[7] = {1, 2, 3, 3, 3, 5, 11};
    int l = 0;
    int r = 6;
    int mid = 0;
    int target = 3;
    int ans1 = -1, ans2 = -1;
    vector<int> ans(2);

    // First binary search for the leftmost occurrence
    while (l <= r) {
        mid = (l + r) / 2;

        if (arr[mid] > target) {
            r = mid - 1;
        } else if (arr[mid] == target) {
            ans1 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    ans[0] = ans1;

    // Resetting l and r for the second binary search
    l = 0;
    r = 6;

    // Second binary search for the rightmost occurrence
    while (l <= r) {
        mid = (l + r) / 2;

        if (arr[mid] > target) {
            r = mid - 1;
        } else if (arr[mid] == target) {
            ans2 = mid;
            l = mid + 1;
        } else {
            l = mid + 1;
        }
    }

    ans[1] = ans2;

    cout << ans[0] << " " << ans[1] << " ";

    return 0;
}