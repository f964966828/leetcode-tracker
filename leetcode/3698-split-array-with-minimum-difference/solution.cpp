class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size(), left_index = 0, right_index = n - 1;
        long long left_sum = nums[0], right_sum = nums[n - 1];
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                left_sum += nums[i + 1];
                left_index = i + 1;
            } else {
                break;
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (nums[i - 1] > nums[i]) {
                right_sum += nums[i - 1];
                right_index = i - 1;
            } else {
                break;
            }
        }

        if (left_index + 1 == right_index) {
            return abs(left_sum - right_sum);
        } else if (left_index == right_index) {
            return min(
                abs(left_sum - right_sum - nums[left_index]),
                abs(left_sum - right_sum + nums[right_index])    
                );
        } else {
            return -1;
        }
    }
};
