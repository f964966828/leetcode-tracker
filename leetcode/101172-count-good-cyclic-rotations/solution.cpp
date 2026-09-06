class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<long long> p_sum(n + 1);
        for (int i = 0; i < n; i++) {
            p_sum[i + 1] = p_sum[i] + nums[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                // first half: (i, pivot)
                // second half: (pivot, n) + (0, i)
                int pivot = i + n / 2 ;
                long long half1 = p_sum[pivot] - p_sum[i];
                long long half2 = p_sum[n] - p_sum[pivot] + p_sum[i];
                ans += (half1 > half2);
            } else {
                // first half: (i, n) + (0, pivot)
                // second half: (pivot, i)
                int pivot = i - n / 2;
                long long half1 = p_sum[n] - p_sum[i] + p_sum[pivot];
                long long half2 = p_sum[i] - p_sum[pivot];
                ans += (half1 > half2);
            }
        }
        return ans;
    }
};
