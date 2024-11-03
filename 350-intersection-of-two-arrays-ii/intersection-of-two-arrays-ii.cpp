class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        
        int cur1 = 0, cur2 = 0;
        
        while(cur1 < nums1.size() && cur2 < nums2.size()){
            if(nums1[cur1] == nums2[cur2]){
                ans.push_back(nums1[cur1]);
                cur1++;
                cur2++;
            }else if(nums1[cur1] < nums2[cur2]){
                cur1++;
            }else{
                cur2++;
            }
        }
        
        return ans;
    }
};