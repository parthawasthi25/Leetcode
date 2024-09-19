class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> stringNums;
        for (int num : nums) {
            stringNums.push_back(to_string(num));
        }
        sort(stringNums.begin(), stringNums.end(), 
             [](const string& a, const string& b) {
                 return a + b > b + a;
             });
        if (stringNums[0] == "0") {
            return "0";
        }
        string result;
        for (const string& numStr : stringNums) {
            result += numStr;
        }

        return result;
    }
};