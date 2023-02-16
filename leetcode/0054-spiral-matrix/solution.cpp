class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int r=0, c=0, dir=0;

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        vector<int> ans;
        for(int i=0; i<n*m; i++){
            ans.push_back(matrix[r][c]);
            visited[r][c] = 1;

            int nr = r+dx[dir], nc = c+dy[dir];
            if(nr<0 || nr>=n || nc<0 || nc>=m || visited[nr][nc]) dir = (dir+1)%4;
            r = r+dx[dir];
            c = c+dy[dir];
        }
        
        return ans;
    }
};
