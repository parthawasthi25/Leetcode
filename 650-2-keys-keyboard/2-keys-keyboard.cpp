class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int prime = 2;
        while(n > 1){
            while(n % prime == 0){
                n /= prime;
                ans += prime;
            }
            prime++;
        }
        return ans;
    }
};