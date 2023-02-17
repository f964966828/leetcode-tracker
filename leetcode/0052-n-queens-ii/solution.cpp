class Solution {
public:
    
    int ans;
    vector<int> rflag, cflag, dflag, rdflag;

    void solve(int n, int c){
        if(n == c) ans++;
        for(int r=0; r<n; r++){
            if(!rflag[r] && !cflag[c] && !dflag[r+c] && !rdflag[n-r+c]){
                rflag[r] = cflag[c] = dflag[r+c] = rdflag[n-r+c] = 1;

                solve(n, c+1);
                
                rflag[r] = cflag[c] = dflag[r+c] = rdflag[n-r+c] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        rflag.resize(n);
        cflag.resize(n);
        dflag.resize(2*n+5);
        rdflag.resize(2*n+5);

        ans = 0;
        solve(n, 0);

        return ans;
    }
};
