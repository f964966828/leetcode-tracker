class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(1, vector<int>(1));
        dp[0][0] = triangle[0][0];
        for(int i=1; i<n; i++){
            vector<int> vec;
            vec.push_back(dp[i-1][0] + triangle[i][0]);
            for(int j=1; j<i; j++)
                vec.push_back(min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]);
            vec.push_back(dp[i-1][i-1] + triangle[i][i]);
            dp.push_back(vec);
        }
        
        int mn = INT_MAX;
        for(int num: dp[n-1])
            mn = min(mn, num);

        return mn;
    }
};
