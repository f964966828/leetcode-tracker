class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = 0, count = 0;
        for(int i=0; i<flowerbed.size(); i++){
            int next = (i != flowerbed.size()-1 ? flowerbed[i+1] : 0);
            int num = flowerbed[i];
            if(!prev && !next && !num){
                count++;
                prev = !num;
            }else{
                prev = num;
            }
        }

        return count >= n;
    }
};
