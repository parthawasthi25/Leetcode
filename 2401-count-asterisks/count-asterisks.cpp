class Solution {
public:
    int countAsterisks(string s) {
        int count1=0;
        int count2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='|')
            count1++;
            if(count1%2==0){
                if(s[i]=='*')
                count2++;
            }
        }return count2;
    }
};