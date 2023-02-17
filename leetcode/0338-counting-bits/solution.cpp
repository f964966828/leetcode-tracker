class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            int cnt = 0, tmp = i;
            while(tmp){
                cnt += (tmp&1);
                tmp >>= 1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
