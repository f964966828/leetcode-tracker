class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<set<vector<int>>> dp(50);
        vector<int> vec;
        for(int c: candidates){
            vec.clear();
            vec.push_back(c);
            dp[c].insert(vec);
        }

        for(int i=0; i<=target; i++){
            for(int c: candidates){
                if(i-c < 0) continue;
                for(vector<int> v: dp[i-c]){
                    vec = v;
                    vec.push_back(c);
                    sort(vec.begin(), vec.end());
                    dp[i].insert(vec);
                }
            }
        }

        vector<vector<int>> ans;
        for(auto v: dp[target]) ans.push_back(v);

        return ans;
    }
};
