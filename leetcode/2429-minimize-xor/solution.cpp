class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt[2] = {0};
        while(num2){
            cnt[num2%2]++;
            num2 /= 2;
        }

        vector<int> n1, x;
        while(num1){
            n1.push_back(num1%2);
            num1 /= 2;
        }
        
        cnt[0] += max(0, (int)n1.size()-cnt[0]-cnt[1]);
        reverse(n1.begin(), n1.end());

        int i = 0;
        while(cnt[0] || cnt[1]){
            int t;
            if(cnt[0]+cnt[1] > n1.size())
                t = (cnt[0] == 0);
            else
                t = n1[i++];
                
            if(cnt[t]){
                x.push_back(t);
                cnt[t]--;
            }else{
                x.push_back(!t);
                cnt[!t]--;
            }
        }

        reverse(x.begin(), x.end());
        int ans = 0, mul = 1;
        for(int n: x){
            ans += n*mul;
            mul *= 2;
        }

        return ans;
    }
};
