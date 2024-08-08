class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
     int directions[5] = {0, 1, 0, -1, 0};
        vector<vector<int>> res = {{rStart, cStart}};
        int j = 0, n = 0;
        while (res.size() != rows * cols){
            for (int i = 0; i < n / 2 + 1; i++){
                rStart += directions[j], cStart += directions[j+1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                    res.push_back({rStart, cStart});
            }
            n++;
            j = (j + 1) % 4;
        }
        return res;        
    }
};