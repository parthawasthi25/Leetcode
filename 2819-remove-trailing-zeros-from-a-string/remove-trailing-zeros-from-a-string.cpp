class Solution {
public:
    string removeTrailingZeros(string num) {
        reverse(num.begin(), num.end());
        int count=0;
        for(int i=0;i<num.length();i++){
            if(num[i]=='0'){
                count++;
            }else break;
        }
        num.erase(0,count);
        reverse(num.begin(),num.end());
        return num;
    }
};