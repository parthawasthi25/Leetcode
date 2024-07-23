class Solution {
public:
    bool isPalindrome(int x) {
    long long rev_num = 0; 
    long long original =x;
    while (x > 0) { 
        rev_num = rev_num * 10 + x % 10; 
        x = x / 10; 
        } 
        if(rev_num == original){
            return true;
        }else return false;
    }
};