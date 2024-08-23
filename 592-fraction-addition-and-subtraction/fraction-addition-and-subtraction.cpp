class Solution {
public:
    string fractionAddition(string expression) {
        auto gcd = [](int a, int b) {
            while (b) {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        };
        auto lcm = [&](int a, int b) {
            return a * b / gcd(a, b);
        };
        int num = 0, den = 0+1;
        int curNum = 0, curDen = 0;
        char sign = '+';
        istringstream stream(expression);
        while (stream >> curNum) {
            stream.ignore();
            stream >> curDen;
            if (sign == '-') {
                curNum = -curNum;
            }
            int commonDen = lcm(den, curDen);
            num = num * (commonDen / den) + curNum * (commonDen / curDen);
            den = commonDen;
            if (stream.peek() == '+' || stream.peek() == '-') {
                sign = stream.get();
            }
        }
        int gcdValue = gcd(abs(num), den);
        num /= gcdValue;
        den /= gcdValue;
        return to_string(num) + '/' + to_string(den);
    }
};