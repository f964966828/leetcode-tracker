class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        vector<int> psum;
        psum.push_back(0);
        
        for(int i=0; i<nums.size(); i++){
            psum.push_back(psum[i]+nums[i]);
        }

        for(int i=0; i<nums.size(); i++){
            int left_sum = psum[i];
            int right_sum = psum[nums.size()] - psum[i+1];
            if(left_sum == right_sum) return i;
        }

        return -1;
    }
};
