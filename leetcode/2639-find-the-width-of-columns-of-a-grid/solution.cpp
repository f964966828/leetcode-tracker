class Solution {
public:
    int findWidth(int num){
        if(num == 0)
            return 1;
            
        int width = 0;
        if(num < 0){
            num = -num;
            width++;
        }
        while(num){
            num /= 10;
            width++;
        }
        return width;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i] = max(ans[i], findWidth(grid[j][i]));
            }
        }
        return ans;
    }
};
