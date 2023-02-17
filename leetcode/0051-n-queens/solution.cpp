class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<int>> grid;
    vector<int> rflag, cflag, dflag, rdflag;

    vector<string> make_string(){
        vector<string> vstr;
        for(auto row: grid){
            string str = "";
            for(auto ch: row){
                str += (ch ? "Q" : ".");
            }
            vstr.push_back(str);
        }
        return vstr;
    }

    void solve(int n, int c){
        if(n == c) ans.push_back(make_string());
        for(int r=0; r<n; r++){
            if(!rflag[r] && !cflag[c] && !dflag[r+c] && !rdflag[n-r+c]){
                rflag[r] = cflag[c] = dflag[r+c] = rdflag[n-r+c] = 1;
                grid[r][c] = 1;

                solve(n, c+1);
                
                grid[r][c] = 0;
                rflag[r] = cflag[c] = dflag[r+c] = rdflag[n-r+c] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        rflag.resize(n);
        cflag.resize(n);
        dflag.resize(2*n+5);
        rdflag.resize(2*n+5);

        grid.resize(n);
        for(int i=0; i<n; i++) grid[i].resize(n);

        solve(n, 0);

        return ans;
    }
};
