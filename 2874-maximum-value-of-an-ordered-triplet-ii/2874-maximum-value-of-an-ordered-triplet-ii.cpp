class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        long long maxNum = nums[0];
        long long maxDiff = LLONG_MIN;
        long long ans = 0;

        for(int k=1; k<n; k++){
            if(maxDiff != LLONG_MIN){
                ans = max(ans, maxDiff * nums[k]);
            }

            maxDiff = max(maxDiff, maxNum - nums[k]);

            maxNum = max(maxNum, (long long)nums[k]);
        }
        return ans;
    }
};