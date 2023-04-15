class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int mx = INT_MIN, n = nums.size();
        vector<int> conver(n);
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            conver[i] = nums[i] + mx;
        }
        
        vector<long long> ans(1, conver[0]);
        for(int i=1; i<n; i++){
            ans.push_back(ans[i-1] + conver[i]);
        }
        
        return ans;
    }
};
