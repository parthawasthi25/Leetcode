class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        auto countPairs = [&](int mid) -> int {
            int count = 0, left = 0;
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mid) {
                    ++left;
                }
                count += right - left;
            }
            return count;
        };

        int low = 0, high = nums.back() - nums.front();

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
