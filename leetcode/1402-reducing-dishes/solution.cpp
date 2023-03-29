class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        vector<int> dp(n+1, INT_MIN);
        dp[0] = 0;
        dp[1] = satisfaction[0];

        for(int i=1; i<n; i++){
            for(int j=i+1; j>=1; j--){
                dp[j] = max(dp[j], dp[j-1] + j * satisfaction[i]);
            }
        }
        
        int mx = INT_MIN;
        for(int num: dp) mx = max(mx, num);

        return mx;
    }
};
