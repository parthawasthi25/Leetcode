class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int highestAltitude = 0;

        for (int g : gain) {
            currentAltitude += g;
            highestAltitude = std::max(highestAltitude, currentAltitude);
        }

        return highestAltitude;
    }
};