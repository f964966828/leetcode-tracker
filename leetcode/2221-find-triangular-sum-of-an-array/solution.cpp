class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> new_nums;
        for (int i = 0; i < nums.size() - 1; i++) {
            new_nums.push_back((nums[i] + nums[i + 1]) % 10);
        }
        return triangularSum(new_nums);
    }
};
