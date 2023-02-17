class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        vector<int> rmax(n), cmax(n);
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                rmax[r] = max(rmax[r], grid[r][c]);
                cmax[c] = max(cmax[c], grid[r][c]);
                if(grid[r][c]) ans += 1;
            }
        }
        for(auto it: rmax) ans += it;
        for(auto it: cmax) ans += it;
        return ans;
    }
};
