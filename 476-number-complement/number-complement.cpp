class Solution {
public:
    int findComplement(int num) {
        if(num == 1) return 0;
        int p = floor(log2(num)) + 1;
        return (long)(1 << p) -1 - num;
    }
};