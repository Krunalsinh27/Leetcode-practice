class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_set<int>seen;

        for(int num : arr){
            freq[num]++;
        }

        for(auto it : freq){
            int count = it.second;

            if(seen.count(count)){
                return false;
            }

            seen.insert(count);
        }
        return true;
    }
};