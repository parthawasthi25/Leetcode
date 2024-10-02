class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return vector<int>();
        vector<int> indices(arr.size()), ans(arr.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), 
            [&arr](const int a, const int b){
                return arr[a] < arr[b];
            });
        int index = indices[0], last_index;
        int rank = 1;
        ans[index] = rank;
        for(int i = 1; i < indices.size(); i++){
            index = indices[i];
            last_index = indices[i-1];
            if(arr[index] != arr[last_index]) rank++;
            ans[index] = rank;
        }
        
        return ans;
    }
};