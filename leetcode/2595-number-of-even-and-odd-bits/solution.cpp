class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        bool flag = true;
        while(n){
            if(flag)
                even += n%2;
            else
                odd += n%2;
            n /= 2;
            flag = !flag;
        }
        return {even, odd};
    }
};
