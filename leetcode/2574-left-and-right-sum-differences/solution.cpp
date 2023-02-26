class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n), rightSum(n), ans(n);
        
        for(int i=1; i<n; i++) leftSum[i] = leftSum[i-1] + nums[i-1];
        for(int i=n-2; i>=0; i--) rightSum[i] = rightSum[i+1] + nums[i+1];
        for(int i=0; i<n; i++) ans[i] = abs(leftSum[i] - rightSum[i]);
        
        return ans;
    }
};
