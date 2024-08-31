class Solution {
public:
    int numDifferentIntegers(string word) {
        for (char& c : word) {
            if (!isdigit(c)) {
                c = ' ';
            }
        }
        stringstream ss(word);
        string temp;
        unordered_set<string> uniqueNumbers;
        while (ss >> temp) {
            while (temp.size() > 1 && temp[0] == '0') {
                temp.erase(temp.begin());
            }
            uniqueNumbers.insert(temp);
        }
        return uniqueNumbers.size();
    }
};