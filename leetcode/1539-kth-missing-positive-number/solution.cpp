class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int n: arr){
            if(n-ans > k){
                return ans+k;
            }else{
                k -= n-ans-1;
                ans = n;
            }
        }

        return ans+k;
    }
};
