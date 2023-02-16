class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> psum(n+1);
        for(int i=1; i<=n; i++) psum[i] = psum[i-1] + nums[i-1];
        
        vector<int> pmin(n+1);
        for(int i=1; i<=n; i++) pmin[i] = min(pmin[i-1], psum[i-1]);

        int ans = -1e9;
        for(int i=1; i<=n; i++) ans = max(ans, psum[i] - pmin[i]);

        return ans;
    }
};
