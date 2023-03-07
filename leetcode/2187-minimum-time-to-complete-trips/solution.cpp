class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 1e15, ans;

        while(l<=r){
            long long mid = (l+r)/2, cnt = 0;
            for(int t: time){
                cnt += mid / t;
                if(cnt >= totalTrips) 
                    break;
            }
            
            if(cnt >= totalTrips){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};
