class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        for (int i = 2; i <= 1000; i++) {
            bool is_prime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) is_prime = false;
            }
            if (is_prime) primes.push_back(i);
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            int diff = nums[i] - nums[i + 1];
            if (diff >= 0) {
                auto iter = upper_bound(primes.begin(), primes.end(), diff);
                if (iter == primes.end()) return false;

                int prime = *iter;
                if (nums[i] > prime) {
                    nums[i] -= prime;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
