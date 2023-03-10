class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        cout << arr.size() << endl;
        int l=1, r=arr.size()-1, ans;
        while(l<=r){
            int m = (l+r)/2;
            cout << " " << m << endl;
            if(arr[m] > arr[m-1]){
                ans = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return ans;
    }
};
