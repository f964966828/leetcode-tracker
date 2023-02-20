class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int cur = -1, mx = 0, cnt = 0, ans = -1;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            if(n%2)
                continue;
            else if(n == cur)
                cnt++;
            else if(n != cur){
                if(cnt > mx){
                    mx = cnt;
                    ans = cur;
                }
                cur = n;
                cnt = 1;
            }
        }
        
        if(cnt > mx) ans = cur;

        return ans;

    }
};
