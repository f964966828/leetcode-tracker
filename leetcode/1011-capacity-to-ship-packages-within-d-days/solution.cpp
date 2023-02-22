class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0, r=0;
        for(int w: weights){
            l = max(l, w);
            r += w;
        }
        int ans;
        while(l<=r){
            int mid = (l+r)/2, d=0, tmp=0;
            for(int w: weights){
                if(tmp+w > mid){
                    tmp = 0;
                    d++;
                }
                tmp += w;
            }
            d++;

            if(d > days)
                l = mid+1;
            else{
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};
