class KthLargest {
private:
    vector<int> kLargest;
public:
    KthLargest(int k, vector<int> nums) {
        kLargest = vector<int>();
        if(nums.size() > 0){
            sort(nums.begin(), nums.end());
            for(vector<int>::reverse_iterator rit = nums.rbegin(); rit < nums.rbegin() + k && rit != nums.rend(); rit++){
                kLargest.push_back(*rit);
            }
        }
        for(int i = kLargest.size(); i < k; i++){
            kLargest.push_back(INT_MIN);
        }
    }
    int add(int val) {
        int k = kLargest.size();
        kLargest.push_back(val);
        
        for(int i = 0; i < k; i++){
            if(val >= kLargest[i]){
                kLargest.insert(kLargest.begin()+i, val);
                break;
            }
        }
        kLargest.resize(k);
        return kLargest[k-1];
    }
};