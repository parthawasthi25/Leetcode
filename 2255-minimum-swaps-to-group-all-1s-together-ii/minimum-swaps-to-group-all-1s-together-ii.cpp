class Solution {
public:
    int minSwaps(vector<int>& nums) {
        long long k = accumulate(nums.begin(), nums.end(), 0);
        long long n = nums.size();
        long long cnt = accumulate(nums.begin(), nums.begin() + k, 0);
        long long mx = cnt;
        for (int i = k; i < n + k; ++i) {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            mx = max(mx, cnt);
        }
        return k - mx;
    }
};