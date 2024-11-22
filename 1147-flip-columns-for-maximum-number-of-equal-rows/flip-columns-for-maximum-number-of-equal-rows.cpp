class Solution {
public:
    bool all1(vector<int>& arr){
        return accumulate(arr.begin(), arr.end(), 1, multiplies<int>()) == 1;
    };
    
    bool allSame(vector<int>& a, vector<int>& b){
        bool flag = true;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                flag = false;
                break;
            }
        }
        return flag;
    };
    
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> sum(n);
        vector<int> reversed(n);
        
        for(int i = 0; i < m; i++){
            int row_friend = 0;
            for(int j = 0; j < m; j++){
                for(int k = 0; k < n; k++){
                    reversed[k] = 1 - matrix[j][k];
                }
                if(matrix[i] == matrix[j] || matrix[i] == reversed){
                    row_friend++;
                }
            }
            ans = max(ans, row_friend);
        }
        
        return ans;
    }
};
