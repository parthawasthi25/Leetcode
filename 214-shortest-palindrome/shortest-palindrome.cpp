
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int tn = 2*n+3;
        string t(tn, '#');
        
        t[0] = '^';
        t[t.size()-1] = '$';
        
        for(int i = 2, j = 0; j < n; i += 2, ++j){
            t[i] = s[j];
        }
        int mirror = 0, right = 0, center = 0;
        vector<int> p(tn, 0);
        
        for(int i = 0; i < tn; ++i){
            mirror = center*2 - i;
            
            if(i < right){
                p[i] = min(p[mirror], right - i);
            }
            
            while(i+p[i]+1 < tn && i-(p[i]+1) >= 0 && t[i-(p[i]+1)] == t[i+p[i]+1]){
                ++p[i];
            }
            
            if(i+p[i] > right){
                center = i;
                right = center + p[center];
            }
        }
        int not_match_start;
        for (int i = tn - 2; i > 0; i--) {
            if (i - p[i] == 1) {
                not_match_start = p[i];
                break;
            }
        }
        string not_match = s.substr(not_match_start); 
        reverse(not_match.begin(), not_match.end());
        return not_match + s;
    }
};