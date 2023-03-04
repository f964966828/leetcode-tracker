class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int cnt = 0, bound = -1;
        for(int i=0; i<ranges.size(); i++){
            int s = ranges[i][0], e = ranges[i][1];
            if(s > bound)
                cnt++;
            bound = max(e, bound);
        }
        
        int ans = 1;
        while(cnt--) ans = (ans * 2) % (int)(1e9+7);
        
        return ans;
    }
};
