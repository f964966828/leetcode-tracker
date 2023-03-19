class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = n*m-1, ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            int i = mid/m, j = mid%m;
            if(matrix[i][j] > target){
                r = mid - 1;
            }else{
                ans = mid;
                l = mid + 1;
            }
        }

        return (matrix[ans/m][ans%m] == target);
    }
};
