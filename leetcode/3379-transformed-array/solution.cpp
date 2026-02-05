class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int idx = ((nums[i] + i) % n + n) % n; 
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};
