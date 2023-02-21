class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        for(int i=0; i<(nums.size()+1)/2; i++){
            int l = i, r = nums.size()-1-i;
            if(l != r)
                ans += stoi(to_string(nums[l]) + to_string(nums[r]));
            else
                ans += nums[l];
        }
        return ans;
    }
};
