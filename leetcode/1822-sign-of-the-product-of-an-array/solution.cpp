class Solution {
public:
    int signFunc(int n){
        if(n > 0)
            return 1;
        else if(n < 0)
            return -1;
        else
            return 0;
    }

    int arraySign(vector<int>& nums) {
        int prod = 1;
        for(int n: nums) prod *= signFunc(n);
        
        return prod;
    }
};
