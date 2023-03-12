class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<int> pvec, nvec;
        for(int n: nums){
            if(n > 0)
                pvec.push_back(n);
            else
                nvec.push_back(n);
        }
        sort(nvec.begin(), nvec.end());
        reverse(nvec.begin(), nvec.end());
        
        long long ans = 0, sum = 0;
        for(int n: pvec){
            sum += n;
            ans++;
        }
        for(int n: nvec){
            sum += n;
            if(sum > 0)
                ans++;
        }
        
        return ans;
    }
};
