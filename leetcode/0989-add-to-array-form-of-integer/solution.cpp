class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        reverse(num.begin(), num.end());
    
        vector<int> ans;
        int carry = 0, idx = 0;
        while(idx < num.size() || k != 0){
            int n = k%10 + carry + (idx<num.size()?num[idx]:0);
            carry = n/10;
            ans.push_back(n%10);
            
            k /= 10;
            idx++;
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
