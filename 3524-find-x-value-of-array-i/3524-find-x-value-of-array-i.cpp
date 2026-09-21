class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);

        vector<long long> dp(k, 0);

        for(int num : nums){
            int rem = num % k;

            vector<long long> next(k, 0);

            next[rem]++;

            for(int oldRem=0; oldRem<k; oldRem++){
                if(dp[oldRem] == 0)
                    continue;
                
                int newRem = (oldRem * rem) % k;

                next[newRem] += dp[oldRem];
            }

            dp = next;

            for(int r=0; r<k; r++){
                result[r] += dp[r];
            }
        }
        return result;
    }
};