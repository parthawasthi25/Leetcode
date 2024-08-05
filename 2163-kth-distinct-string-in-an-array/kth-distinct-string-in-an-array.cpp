class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
    map<string, int> b;
    long n = arr.size();
    for (int i = 0; i < n; i++) {
        b[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (b[arr[i]] == 1) {
            k--;  
            if (k == 0) {
                return arr[i];
            }
        }
    }return "";
    }
};