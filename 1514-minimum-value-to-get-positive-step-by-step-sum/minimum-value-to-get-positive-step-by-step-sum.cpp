class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int cumMin = INT_MAX;
        int cumSum = 0;
        
        for(int num : nums){
            cumSum += num;
            cumMin = min(cumMin, cumSum);
        }
        
        if(cumMin > 0) return 1;
        return -cumMin + 1;
    }
};