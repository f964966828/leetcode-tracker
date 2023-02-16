class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int num = nums[i] + nums[j] + nums[k];
                if(num == 0){
                    vector<int> seq {nums[i], nums[j], nums[k]};
                    s.insert(seq);
                    j++;
                }else if(num < 0){
                    j++;
                }else if(num > 0){
                    k--;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto it: s) ans.push_back(it);

        return ans;
    }
};
