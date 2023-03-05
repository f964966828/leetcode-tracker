class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        map<int, int> mp1, mp2;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i], div = 2;
            while(n > 1){
                while(n%div == 0){
                    n /= div;
                    if(i==0)
                        mp1[div]++;
                    else
                        mp2[div]++;
                }
                div++;
                if(div > sqrt(n)) div = n;
            }
        }
        
        for(int i=1; i<nums.size(); i++){
            bool flag = true;
            for(auto m: mp1){
                if(mp2[m.first] != 0) 
                    flag = false;
                else
                    mp1.erase(m.first);
            }
                
            if(flag) return i-1;
            
            int n = nums[i], div = 2;
            while(n > 1){
                while(n%div == 0){
                    n /= div;
                    mp2[div]--;
                    mp1[div]++;
                }
                div++;
                if(div > sqrt(n)) div = n;
            }
        }
        
        return -1;
    }
};
