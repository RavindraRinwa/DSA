#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    void helper(vector<vector<int>> &res, vector<int> &temp, vector<int> nums, int idx)
    {
        if(idx == nums.size())
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(res, temp, nums, idx+1);
        temp.pop_back();
        helper(res, temp, nums, idx+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, nums, 0);
        return res;
    }
};
int main(){
    
    // vector<int>nums(3) = {1,2,3};
    vector<int>nums = {1,2,3};
    Solution solution;
    solution.subsets(nums);


}