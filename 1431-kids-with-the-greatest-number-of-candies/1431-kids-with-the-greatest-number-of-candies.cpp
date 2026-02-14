class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int currMax = 0;
        for(int i : candies){
            currMax = max(currMax, i);
        }
        vector<bool> ans(candies.size());
        for(int i=0; i<candies.size(); i++){
            if(candies[i] + extraCandies >= currMax){
                ans[i] = true;
            }else{
               ans[i] = false;
            }
        }
        return ans;
    }
};