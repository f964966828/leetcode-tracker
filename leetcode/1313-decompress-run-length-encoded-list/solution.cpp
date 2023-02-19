class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i*2<nums.size(); i++){
            int freq = nums[2*i], val = nums[2*i+1];
            while(freq--) ans.push_back(val);
        }
        return ans;
    }
};
