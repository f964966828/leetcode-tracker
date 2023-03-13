class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<vector<int>> &ans) {
        if(idx >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=idx; j<nums.size(); j++){
            swap(nums[idx], nums[j]);
            solve(idx+1, nums, ans);
            swap(nums[idx], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};
