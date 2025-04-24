class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            if (i + 1 < n && nums[i + 1] == cur) {
                nums[count] = nums[count + 1] = cur;
                count += 2;
            } else {
                nums[count++] = cur;
            }
            while (i + 1 < n && nums[i + 1] == cur) i++;
        }
        return count;
    }
};
