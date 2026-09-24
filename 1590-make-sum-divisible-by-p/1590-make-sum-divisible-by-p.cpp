class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        
        for(int num : nums){
            totalSum += num;
        }

        int target = totalSum % p;

        if(target == 0)
            return 0;

        unordered_map<int, int> mp;

        mp[0] = -1;

        long long prefixSum = 0;
        int minLen = nums.size();
        
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];

            int currentRem = prefixSum % p;

            int needed = (currentRem - target + p) % p;

            if(mp.find(needed) != mp.end()){
                int len = i - mp[needed];

                minLen = min(minLen, len);
            }
            mp[currentRem] = i;
        }

        if(minLen == nums.size()){
            return -1;
        }
        return minLen;
    }
};