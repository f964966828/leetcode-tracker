class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 1e18, ans;
        while(l <= r){
            long long m = (l+r)/2, count = 0;
            for(int r: ranks){
                count += floor(sqrt(1.0 * m / r));
                //cout << " " << m << " " << r << " " << floor(sqrt(1.0 * m / r)) << endl; 
            }
            
            if(count >= cars){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
            
            //cout << l << " " << r << endl;
        }
        
        return ans;
    }
};
