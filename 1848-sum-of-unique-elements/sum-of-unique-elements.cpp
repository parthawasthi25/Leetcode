class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
        int sum = 0;
        for (auto& pair : frequency) {
            if (pair.second == 1) {
                sum += pair.first;
            }
        }
        return sum;
    }
};
