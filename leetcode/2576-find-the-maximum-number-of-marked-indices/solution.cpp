class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        multiset<int> ms1, ms2;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()/2; i++) ms1.insert(nums[i]);
        for(int i=nums.size()/2; i<nums.size(); i++) ms2.insert(nums[i]);
        
        int ans = 0;
        while(!ms1.empty() && !ms2.empty()){
            auto iter = ms1.begin();
            auto find = ms2.lower_bound((*iter) * 2);
            if(find != ms2.end()){
                ms1.erase(iter);
                ms2.erase(find);
                ans += 2;
            }else{
                break;
            }
        }

        
        return ans;
    }
};
