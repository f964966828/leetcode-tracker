class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> counts(105);
        for (int num : nums) counts[num]++;

        vector<int> ans;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j < min(counts[i], k); j++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
