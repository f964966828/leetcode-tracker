class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int exists[100] = {0};
        for(auto it: nums){
            int exp = 0, num = 1;
            while(num < it){
                num *= 2;
                exp += 1;
            }
            if(num == it) exists[exp] = 1;
        }
        
        for(int i=0; i<100; i++){
            if(!exists[i]){
                return pow(2, i);
            }
        }
        
        return 0;
    }
};
