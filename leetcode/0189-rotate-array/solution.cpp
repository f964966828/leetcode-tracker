class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + temp, nums.end());
        reverse(nums.begin(), nums.begin() + temp);
    }
};
