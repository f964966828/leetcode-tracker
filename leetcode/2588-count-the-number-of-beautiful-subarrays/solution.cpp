class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        vector<int> pxor(1, 0);
        for(int i=1; i<=nums.size(); i++)
            pxor.push_back(pxor[i-1] ^ nums[i-1]);
        
        map<int, int> mp;
        long long ans = 0;
        for(int n: pxor){
            ans += mp[n];
            mp[n]++;
        }
        
        return ans;
    }
};
