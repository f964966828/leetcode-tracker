class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> p_sum(1, 0);
        for (int i = 0; i < n; i++) {
            p_sum.push_back(p_sum[i] + nums[i]);
        }

        map<int, int> records;
        for (int i = 0; i <= n; i++) {
            int num = p_sum[i];
            if (records.find(num % k) != records.end()) {
                if (i - records[num % k] >= 2) {
                    return true;
                }
            } else {
                records[num % k] = i;
            }
        }

        return false;
    }
};
