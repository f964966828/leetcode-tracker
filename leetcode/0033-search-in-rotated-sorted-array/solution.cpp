class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            const int m = (l + r) / 2;
            if (nums[m] < nums[r]) 
                r = m;
            else 
                l = m + 1;
        }

        int p = l, n = nums.size();
        l = 0, r = nums.size() - 1;
        while(l <= r) {
            const int m = (l + r) / 2;
            if (nums[(m+p)%n] == target) return (m+p)%n;
            if (nums[(m+p)%n] < target) 
                l = m + 1;
            else 
                r = m - 1;
        }

        return -1;
    }
};
