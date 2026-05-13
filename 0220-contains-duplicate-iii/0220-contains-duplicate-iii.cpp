class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;

        for(int i=0; i<nums.size(); i++){
            long long low = (long long)nums[i] - valueDiff;
            long long high = (long long)nums[i] + valueDiff;

            auto it = window.lower_bound(low);

            if(it != window.end() && *it <= high){
                return true;
            }

            window.insert(nums[i]);

            if(window.size() > indexDiff){
                window.erase(nums[i - indexDiff]);
            }
        }
        return false;
    }
};