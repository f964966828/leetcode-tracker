class Solution {
public:
    int solve(vector<int>& nums, vector<int>& seq, int pos, int k){
        if(pos == nums.size()){
            if(seq.size())
                return 1;
            else
                return 0;
        }
        
        bool flag = true;
        for(int num: seq){
            if(abs(nums[pos] - num) == k){
                flag = false;
            }
        }
        
        int ans = solve(nums, seq, pos+1, k);
        if(flag){
            seq.push_back(nums[pos]);
            ans += solve(nums, seq, pos+1, k);
            seq.erase(--seq.end());
        }
        
        return ans;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> seq;
        return solve(nums, seq, 0, k);
    }
};
