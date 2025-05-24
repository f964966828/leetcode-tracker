class Solution {
public:
    bool isPrime(long long num) {
        if (num == 1) return false;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    
    long long sumOfLargestPrimes(string s) {
        set<long long> st;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                long long num = 0;
                for (int k = i; k <= j; k++) {
                    num = num * 10 + s[k] - '0';
                }
                if (isPrime(num)) st.insert(num);
            }
        }
        
        vector<long long> vec(st.rbegin(), st.rend());
        long long ans = 0;
        for (int i = 0; i < min((int)vec.size(), 3); i++) {
            ans += vec[i];
        }
            
        return ans;
    }
};
