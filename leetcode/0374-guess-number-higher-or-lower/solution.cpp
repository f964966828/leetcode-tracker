/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l=0, r=INT_MAX;
        while(l<=r){
            long long mid = (l+r)/2;
            int g = guess(mid);
            if(g == -1){
                r = mid-1;
            }else if(g == 1){
                l = mid+1;
            }else if(g == 0){
                return mid;
            }
        }
        return 0;
    }
};
