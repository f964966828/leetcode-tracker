class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> counts(105);
        counts[nums[0]]++;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                counts[nums[i]]++;
            }
        }

        int ans = 0;
        for (int i = 0; i <= 100; i++) {
            ans += (counts[i] == 1);
        }
        
        return ans;
    }
};
