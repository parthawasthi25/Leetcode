class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int col;
        if(ruleKey=="type"){
            col = 0;
        }
        else if(ruleKey=="color"){
            col=1;
        }
        else{
            col=2;
        }
        int ans=0;
        for(int i=0;i<items.size();i++){
            if(items[i][col]==ruleValue){
                ans++;
            }
        }
        return ans;
    }
};