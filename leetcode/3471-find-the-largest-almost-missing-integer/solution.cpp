class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            int mx = -1;
            for (int num : nums) mx = max(mx, num);
            return mx;
        } else {
            vector<int> freq(51);
            for (int num : nums) freq[num]++;
            
            int mx = -1;
            if (k == 1) {
                for (int i = 0; i <= 50; i++) if (freq[i] == 1) mx = max(mx, i);
            } else {
                if (freq[nums[0]] == 1) mx = max(mx, nums[0]);
                if (freq[nums[n - 1]] == 1) mx = max(mx, nums[n - 1]);
            }
            return mx;
        }
    }
};
