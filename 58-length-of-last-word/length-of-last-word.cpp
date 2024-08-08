class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        int flag=0;
        for(int i=s.length()-1;i>=0;i--){
            if(flag==0 && s[i]==' '){
                continue;
            }
            if(s[i]!=' '){
                flag =1;
                cnt++;
            }else break;
        }return cnt;
    }
};