class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=1e9, ans;
        while(l<=r){
            int m = (l+r)/2, cnt = 0;
            
            for(int p: piles){
                cnt += ceil(1.0*p/m);
                if(cnt > h) break;
            }

            if(cnt <= h){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};
