class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> points(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                points[grid[i][j]] = {i, j};
            }
        }
        cout << endl;
        
        int r = points[0].first;
        int c = points[0].second;
        
        if(r != 0 || c != 0)
            return false;
        
        for(int i=1; i<n*n; i++){
            int nr = points[i].first;
            int nc = points[i].second;
            int dr = abs(nr - r);
            int dc = abs(nc - c);
            
            if(max(dr, dc) != 2 || min(dr, dc) != 1)
                return false;
            
            r = nr;
            c = nc;
        }
        
        return true;
    }
};
