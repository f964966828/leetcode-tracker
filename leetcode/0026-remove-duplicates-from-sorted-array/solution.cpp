class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            while (i + 1 < n && nums[i + 1] == cur) i++;
            if (i < n && count) swap(nums[i], nums[count]);
            count++;
        }
        return count;
    }
};
