class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>> dp(target+1, vector<int>(n+1));
        dp[0][0] = 1;
        for(int i=1; i<=types.size(); i++){
            for(int t=0; t<=target; t++){
                int count = types[i-1][0], mark = types[i-1][1];
                for(int c=0; c<=count; c++){
                    int num = t - mark * c;
                    if(num >= 0 && num <= target) 
                        dp[t][i] = (dp[t][i] + dp[num][i-1]) % (int)(1e9+7);
                }
            }
        }
        return dp[target][n];
    }
};
