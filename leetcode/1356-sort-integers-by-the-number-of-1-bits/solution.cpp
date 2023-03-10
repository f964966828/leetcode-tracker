int bitCounter(int n){
    int cnt = 0;
    while(n){
        cnt += n%2;
        n /= 2;
    }
    return cnt;
}

bool cmp(int a, int b){
    int c1 = bitCounter(a), c2 = bitCounter(b);
    if(c1 == c2)
        return a < b;
    else
        return c1 < c2;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
