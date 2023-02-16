class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1, cnt = 0;
        for(auto it: nums){
            if(it == 0) cnt++;
            else total *= it;
        }
        
        vector<int> ans;
        for(auto it: nums) {
            if(cnt == 0) ans.push_back(total/it);
            else if(cnt == 1 && it == 0) ans.push_back(total);
            else if(cnt == 1 && it != 0) ans.push_back(0);
            else if(cnt >= 2) ans.push_back(0);
        }
        return ans;
    }
};
