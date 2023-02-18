class Solution {
public:
    int convert(int num, int from, int to){
        string str = to_string(num);
        for(int i=0; i<str.size(); i++){
            if(str[i] == from+'0') str[i] = to+'0';
        }
        return stoi(str);
    }
    int minMaxDifference(int num) {
        
        int mx = num, mn = num;
        for(int i=0; i<=9; i++){
            for(int j=0; j<=9; j++){
                int ret = convert(num, i, j);
                mx = max(mx, ret);
                mn = min(mn, ret);
            }
        }
        
        return mx-mn;
        
    }
};
