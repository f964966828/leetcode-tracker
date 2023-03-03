class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int c = 0, t = 0;
        for(int n: nums)
            if(n < target) 
                c++;
            else if(n == target)
                t++;

        vector<int> ans;
        for(int i=0; i<t; i++) ans.push_back(c+i);

        return ans;
    }
};
