class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0;
        for (int num: nums) mx = max(mx, num);

        vector<int> p_cnt(1, 0);
        for (int i = 0; i < nums.size(); i++) {
            p_cnt.push_back(p_cnt[i] + (nums[i] == mx));
        }

        long long ans = 0;
        for (int i = 0; i < p_cnt.size(); i++) {
            auto iter = lower_bound(p_cnt.begin(), p_cnt.end(), p_cnt[i] - k + 1);
            //cout << p_cnt[i] << " " << *iter << " " << (iter - p_cnt.begin()) << endl;
            if (p_cnt[i] - *iter + 1 >= k) {
                ans += (iter - p_cnt.begin());
            }
        }

        return ans;
    }
};
