class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_head = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0 && zero_head == -1)
                zero_head = i;
            if(nums[i] != 0 && zero_head != -1){
                swap(nums[i], nums[zero_head]);
                zero_head++;
            }
        }
    }
};
