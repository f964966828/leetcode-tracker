class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v.resize(n);
        for(int i=0; i<n; i++){
            v[nums[i]-1] = 1;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!v[i])ans.push_back(i+1);
        }
        return ans;
    }
};
