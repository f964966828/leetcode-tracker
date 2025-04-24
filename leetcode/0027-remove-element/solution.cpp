class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), l = 0, r = n - 1;
        if (n == 0) return 0;
        while (l < r) {
            while (r >= 0 && nums[r] == val) r--;
            while (l < n && nums[l] != val) l++;
            if (l < r) swap(nums[l++], nums[r--]);
        }
        while (r >= 0 && nums[r] == val) r--;
        return r + 1;
    }
};
