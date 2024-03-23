class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        int ans_diff = 1e8, n = nums.size();
        for(int i = 0; i < n; i++){
            int j = i + 1, k = n - 1;
            while (j < k) {
                int num = nums[i] + nums[j] + nums[k];
                int diff = num - target;
                if (diff <= 0) {
                    j++;
                } else {
                    k--;
                }
                if (abs(diff) < abs(ans_diff)) {
                    ans_diff = diff;
                }
            }
        }

        return ans_diff + target;
    }
};
