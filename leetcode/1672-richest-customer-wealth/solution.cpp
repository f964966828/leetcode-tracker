class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto account: accounts){
            int sum = 0;
            for(int w: account) 
                sum += w;
            ans = max(ans, sum);
        }

        return ans;
    }
};
