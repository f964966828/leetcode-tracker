class Solution {
public:
    bool isHappy(int n) {
        for(int i=0; i<100; i++){
            int nn = 0;
            while(n){
                nn += (n%10)*(n%10);
                n /= 10;
            }
            n = nn;
        }
        return n == 1;
    }
};
