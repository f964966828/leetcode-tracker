class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = nums[0], count = 1;
        vector<int> new_nums;
        for (int num: nums) {
            if (cur != num) {
                new_nums.push_back(cur);
                cur = num;
                count++;
            }
        }
        new_nums.push_back(cur);
        nums = new_nums;
        return count;
    }
};
