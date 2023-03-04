class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int bound = -1;
        int minI = -1, maxI = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                minI = (nums[i] == minK ? i : minI);
                maxI = (nums[i] == maxK ? i : maxI);
                ans += max(0, min(minI, maxI) - bound);
            }else{
                bound = i;
                minI = -1;
                maxI = -1;
            }
        }

        return ans;
    }
};
