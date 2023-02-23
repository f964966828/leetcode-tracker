class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(), digits.end());
        
        int out = 1;
        for(int i=0; i<digits.size(); i++){
            digits[i] = digits[i] + out;
            if(digits[i] == 10){
                digits[i] = 0;
                out = 1;
            }else out = 0;
        }
        
        if(out) digits.push_back(out);
        reverse(digits.begin(), digits.end());
        
        return digits;
    }
};
