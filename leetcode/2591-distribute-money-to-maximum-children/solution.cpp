class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children)
            return -1;
        
        if(money == 4 && children == 1)
            return -1;
        
        int ans = 0;
        while(children){
            if(children == 2 && money == 12){
                money -= 9;
            }if(children == 1){
                if(money == 8) ans++;
            }else if(money >= 7 + children){
                money -= 8;
                ans++;
            }else{
                break;
            }
                
            children--;
        }
        
        return ans;
    }
};
