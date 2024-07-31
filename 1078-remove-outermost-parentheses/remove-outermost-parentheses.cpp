class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string a="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
                if(count>1){
                    a=a+s[i];
                }
            }
            else if(s[i]==')'){
                count--;
                if(count>0){
                    a=a+s[i];
                }
            }
        }return a;
    }
};