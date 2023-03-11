class NumArray {
public:

    vector<int> psum;

    NumArray(vector<int>& nums) {
        psum.push_back(0);
        for(int i=0; i<nums.size(); i++)
            psum.push_back(psum[i] + nums[i]);
    }
    
    int sumRange(int left, int right) {
        return psum[right+1] - psum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
