class Solution {
public:
    int romanToInt(string s) {
    long long ans = 0;
    vector<long long> roman(128);
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    for (int i = 0; i + 1 < s.length(); ++i)
      if (roman[s[i]] < roman[s[i + 1]])
        ans -= roman[s[i]];
      else
        ans += roman[s[i]];

    return ans + roman[s.back()];
    }
};