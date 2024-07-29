class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>zeros;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros.push_back(nums[i]);
            }
        }
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        nums.insert(nums.end(), zeros.begin(), zeros.end());
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
    }
};

/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>zero;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0);
            zero.push_back(nums[i]);
        }
        nums.erase(remove(nums.begin(),nums.end(),0),nums.end());
        nums.insert(nums.end(),zero.begin(),zero.end());
        for(int i=0;i<nums.size();i++)
        cout<<nums[i];
    }
};
*/