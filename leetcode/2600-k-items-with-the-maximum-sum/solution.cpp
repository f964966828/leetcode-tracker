class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int Ones = min(numOnes, k);
        k -= Ones;
        
        int Zeros = min(numZeros, k);
        k -= Zeros;
        
        int NegOnes = min(numNegOnes, k);
        k -= NegOnes;
        
        return Ones - NegOnes;
    }
};
