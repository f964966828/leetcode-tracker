class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> psum;
        psum.push_back(0);
        for(int i=1; i<=arr.size(); i++)
            psum.push_back(psum[i-1] + arr[i-1]);
        
        int sum = 0;
        for(int l=1; l<=arr.size(); l+=2){
            for(int i=0; i+l<=arr.size(); i++)
                sum += psum[i+l] - psum[i];
        }

        return sum;
    }
};
