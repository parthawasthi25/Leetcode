class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>ss;
        long long Mod=1e9+7;
        long long cs;
        long long sum=0;
        for(int i=0;i<n;i++){
            cs=nums[i];
            ss.push_back(cs);
                for(int j=i+1;j<n;j++){
                    cs=nums[j]+cs;
                    ss.push_back(cs);
                }
        }
        sort(ss.begin(), ss.end());
        sum = accumulate(ss.begin() + (left - 1), ss.begin() + right, 0, [&](int a, int b) {return (a + b) % Mod;});
        return sum;  
    }
};