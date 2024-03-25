class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<bool> flags(n, false);
        
        vector<int> ans;
        for (int num: nums) {
            if (flags[num]) {
                ans.push_back(num);
            } else {
                flags[num] = true;
            }
        }

        return ans;
    }
};
