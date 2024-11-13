class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        long long ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            int target_low = lower - nums[i];
            int target_high = upper - nums[i];

            if (target_high < nums[0]) continue;
            
            auto iter_low = lower_bound(nums.begin(), nums.end(), target_low);
            auto iter_high = --upper_bound(nums.begin(), nums.end(), target_high);
            
            int index_low = iter_low - nums.begin();
            int index_high = min((int)(iter_high - nums.begin()), i - 1);
            cout << nums[i] << " " << index_low << " " << index_high << endl;
            ans += max((index_high - index_low + 1), 0);
        }

        return ans;
    }
};
