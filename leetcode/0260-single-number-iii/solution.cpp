class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    
        set<int> s1, s2;    
        for(auto it: nums){
            if(s1.find(it) != s1.end()) s2.insert(it);
            s1.insert(it);
        }

        vector<int> ans;
        for(auto it: s1){
            if(s2.find(it) == s2.end()) ans.push_back(it);
        }

        return ans;
    }
};
