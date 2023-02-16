class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int depth = grid.size(), num = grid[0].size();
        vector<int> ans;
        for(int i=0; i<num; i++){
            int c=i, r=0;
            while(r != depth){
                if(grid[r][c] == 1){
                    if(c+1>=num || grid[r][c+1] != 1) break;
                    c = c+1;
                    r = r+1;
                }else if(grid[r][c] == -1){
                    if(c-1<0 || grid[r][c-1] != -1) break;
                    c = c-1;
                    r = r+1;
                }
            }
            if(r != depth) ans.push_back(-1);
            else ans.push_back(c);
        }   
        return ans;
    }
};
