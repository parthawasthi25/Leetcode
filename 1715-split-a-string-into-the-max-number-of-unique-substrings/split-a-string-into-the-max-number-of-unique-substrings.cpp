class Solution {
public:
    void backtrack(int cur, string& s, 
       unordered_set<string>& split, int& ans){
        if(cur == s.size()){
            ans = max(ans, (int)split.size());
        }else{
            for(int l = 1; l <= s.size() - cur; ++l){
                if(split.find(s.substr(cur, l)) == split.end()){
                    split.insert(s.substr(cur, l));
                    backtrack(cur+l, s, split, ans);
                    split.erase(s.substr(cur, l));
                }
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> split;
        int ans = 0;
        
        backtrack(0, s, split, ans);
        
        return ans;
    }
};