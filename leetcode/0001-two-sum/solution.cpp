class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> diff(nums.size());
        vector<int> ans(2);
        int mid = 0;
        for(int i=0; i<nums.size(); i++){
            diff[i] = target - nums[i];
            if(nums[i] == target/2) mid++;
        }
        sort(diff.begin(), diff.end());

        for(int i=0; i<nums.size(); i++){
            auto lower = lower_bound(diff.begin(), diff.end(), nums[i]);
            
            if(lower != diff.end() && nums[i] == *lower){
                if(nums[i] != target / 2 || (nums[i] == target / 2 && mid != 1)){
                    ans[0] = i;
                }
                //cout << nums[ans[0]] << endl;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(target - nums[ans[0]] == nums[i] && ans[0] != i) ans[1] = i; 
        }
        
        return ans;
    }
};
