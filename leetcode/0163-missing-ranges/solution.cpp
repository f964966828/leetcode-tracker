class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;

        if (nums.size() > 0) {
            if (nums[0] != lower) {
                ans.push_back(vector<int> {lower, nums[0] - 1});
            }
            lower = nums[0];
        }
        
        for (int &num : nums) {
            if (num > lower + 1) {
                ans.push_back(vector<int> {lower + 1, num - 1});
            }
            lower = num;
        }

        if (nums.size() > 0) {
            if (lower != upper) {
                ans.push_back(vector<int> {lower + 1, upper});
            }
        } else {
            ans.push_back(vector<int> {lower, upper});
        }

        return ans;
    }
};
