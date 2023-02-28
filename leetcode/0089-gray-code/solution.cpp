class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if(n == 0){
            ans.push_back(0);
            return ans;
        }else{
            vector<int> prev = grayCode(n-1);
            for(int i=0; i<prev.size(); i++) ans.push_back(prev[i]);
            for(int i=prev.size()-1; i>=0; i--) ans.push_back(prev[i] + pow(2, n-1));
        }

        return ans;
    }
};
