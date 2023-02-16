class Solution {
public:
    int findMax(vector<int>& vec){
        int n = vec.size();
        vector<int> pmul(n+1, 1);
        for(int i=1; i<=n; i++) pmul[i] = pmul[i-1] * vec[i-1];
        
        vector<int> ppmin(n+1, 1e9), npmax(n+1, -1e9);
        for(int i=1; i<=n; i++) {
            ppmin[i] = min(ppmin[i-1], (pmul[i-1]>0?pmul[i-1]:(int) 1e9) );
            npmax[i] = max(npmax[i-1], (pmul[i-1]<0?pmul[i-1]:(int)-1e9) );
        }
        
        int ans = -1e9;
        for(int i=1; i<=n; i++) {
            if(pmul[i]>0){
                ans = max(ans, pmul[i]/ppmin[i]);
            }else if(pmul[i]<0){
                ans = max(ans, pmul[i]/npmax[i]);
            }
        }

        return ans;
    }
    int maxProduct(vector<int>& A) {
        int n = A.size();
        // store the result that is the max we have found so far
        int r = A[0];

        // imax/imin stores the max/min product of
        // subarray that ends with the current number A[i]
        for (int i = 1, imax = r, imin = r; i < n; i++) {
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if (A[i] < 0)
                swap(imax, imin);

            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            imax = max(A[i], imax * A[i]);
            imin = min(A[i], imin * A[i]);

            // the newly computed max value is a candidate for our global result
            r = max(r, imax);
        }
        return r;
    }
};

int maxProduct(int A[], int n) {
    // store the result that is the max we have found so far
    int r = A[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number A[i]
    for (int i = 1, imax = r, imin = r; i < n; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}
