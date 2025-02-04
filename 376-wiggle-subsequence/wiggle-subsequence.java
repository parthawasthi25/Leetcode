class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums.length < 2) return nums.length;
        int UL = 1, LL = 1;
        for(int i = 1;i < nums.length;i++){
            if(nums[i] > nums [i-1]){
                LL = UL + 1;
            }else if(nums[i] < nums[i-1]){
                UL = LL + 1;
            }
        }
        return Math.max(UL, LL);
    }
}
