class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, count1 = 0, count2 = 0;
        for (int &num : nums1) {
            sum1 += num;
            count1 += (num == 0);
        }
        for (int &num : nums2) {
            sum2 += num;
            count2 += (num == 0);
        }

        long long ans1 = sum1 + count1;
        long long ans2 = sum2 + count2;
        if (ans1 > ans2 && count2 == 0) {
            return -1;
        } else if (ans2 > ans1 && count1 == 0) {
            return -1;
        } else {
            return max(ans1, ans2);
        }
    }
};
