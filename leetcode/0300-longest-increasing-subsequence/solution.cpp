class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for(int i=0; i<nums.size(); i++){
            int idx = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
            if(idx == seq.size())
                seq.push_back(nums[i]);
            else 
                seq[idx] = nums[i];
        }
        return seq.size();
    }
};
