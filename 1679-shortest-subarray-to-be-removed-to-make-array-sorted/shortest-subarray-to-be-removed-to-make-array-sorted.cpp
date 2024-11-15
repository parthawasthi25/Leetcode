class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int l = 0, r = n-1;
        
        while(l+1 < n && arr[l] <= arr[l+1]){
            ++l;
        }
        if(l == n-1) return 0;
        
        while(r-1 > 0 && arr[r-1] <= arr[r]){
            --r;
        }
        int min_len = min(n-1-l, r);
        for(int i = 0, j = r; i <= l && j < n; ++i){
            while(j < n && arr[i] > arr[j]){
                ++j;
            }
            if(j < n){
                min_len = min(min_len, j-1-i);
            }
        }
        
        return min_len;
    }
};