int dr[] = {-1, -1, -1, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, 0, -1, 0, 1};

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans = 0;
        for(int r=1; r<grid.size()-1; r++){
            for(int c=1; c<grid[0].size()-1; c++){
                int sum = 0;
                for(int d=0; d<7; d++)
                    sum += grid[r+dr[d]][c+dc[d]];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
