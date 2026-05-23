class Solution {
public:
    vector<pair<int, int>> calc(vector<int> &vec, int k) {
        vector<pair<int, int>> ret;
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (int num : vec) {
                sum += min((i - num + k) % k, (num - i + k) % k);
            }
            ret.push_back({sum, i});
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
    
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odd, even;
        for (int i = 0; i < n; i++) {
            if (i % 2) even.push_back(nums[i] % k);
            else odd.push_back(nums[i] % k);
        }

        vector<pair<int, int>> ret1 = calc(odd, k);
        vector<pair<int, int>> ret2 = calc(even, k);
        if (ret1[0].second != ret2[0].second) {
            return ret1[0].first + ret2[0].first;
        } else {
            return min(
                ret1[0].first + ret2[1].first,
                ret1[1].first + ret2[0].first
            );
        }
    }
};
