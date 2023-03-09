bool cmp(int a, int b){
    return a > b;
}

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        for(int i=0; i<nums.size()-2; i++){
            int a=nums[i], b=nums[i+1], c=nums[i+2];
            if(a<b+c) return a+b+c;
        }

        return 0;
    }
};
