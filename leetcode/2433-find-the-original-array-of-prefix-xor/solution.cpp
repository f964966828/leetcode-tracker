class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int temp = 0;
        vector<int> ans;
        for(int i=0; i<pref.size(); i++){
            ans.push_back(temp ^ pref[i]);
            temp ^= ans[i];
        }
        return ans;
    }
};
