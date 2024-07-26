class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maximum=0;
        int n=nums.size();
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