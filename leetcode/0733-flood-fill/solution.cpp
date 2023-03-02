int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

class Solution {
public:
    void dfs(int r, int c, int origin, int target, vector<vector<int>>& image){
        image[r][c] = target;
        int n = image.size(), m = image[0].size();
        for(int d=0; d<4; d++){
            int nr = r+dr[d], nc = c+dc[d];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == origin)
                dfs(nr, nc, origin, target, image);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color != image[sr][sc]) dfs(sr, sc, image[sr][sc], color, image);
        return image;
    }
};
