class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> count(value);
        set<int> s;
        for(int num: nums){
            if(num < 0)
                num -= (num/value-1) * value;
                
            int base = num%value;
            s.insert(base + value*count[base]);
            count[base]++;       
        }
        
        int ans = 0;
        for(int num: s){
            if(num == ans)
                ans++;
        }
        
        return ans;
    }
};
