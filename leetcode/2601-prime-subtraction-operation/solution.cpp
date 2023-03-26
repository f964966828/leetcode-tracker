class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes(1, 0);
        for(int i=2; i<=1000; i++){
            bool isPrime = true;
            for(int k=2; k<i; k++){
                if(i%k == 0) isPrime = false;
            }
            if(isPrime) primes.push_back(i);
        }
        
        int prev = 0;
        for(int num: nums){
            int target = num - prev;
            if(target <= 0)
                return false;
            
            auto iter = --lower_bound(primes.begin(), primes.end(), target);
            prev = num - *iter;
            
            //cout << prev << " ";
        }
        //cout << endl;
        
        return true;
    }
};
