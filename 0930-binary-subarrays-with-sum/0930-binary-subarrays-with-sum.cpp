class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;

        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];

            int needed = prefixSum - goal;

            count += mp[needed];

            mp[prefixSum]++;
        }
        return count;
    }
};