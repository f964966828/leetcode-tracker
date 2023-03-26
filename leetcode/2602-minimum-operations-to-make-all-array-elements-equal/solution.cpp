class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<long long> psum(1, 0);
        for(int i=1; i<=n; i++){
            psum.push_back(psum[i-1] + nums[i-1]);
        }
        
        vector<long long> result;
        for(int q: queries){
            q = (long long) q;
            long long i = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long left = (q * i - psum[i]);
            long long right = (psum[n] - psum[i] - q * (n-i));
            result.push_back(left + right);
        }
        
        return result;
    }
};
