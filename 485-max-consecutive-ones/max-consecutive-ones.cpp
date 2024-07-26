class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        long long count=0;
        long long maximum=0;
        long long n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }else{
                count=0;
            }
            maximum=max(count,maximum);
        }return maximum;
    }
};