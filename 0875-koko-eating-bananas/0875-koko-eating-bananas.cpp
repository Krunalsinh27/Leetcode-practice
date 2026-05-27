class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;

        while(left <= right){
            int mid = left + (right-left)/2;

            long long totalHour = 0;

            for(int pile : piles){
                totalHour += ceil((double)pile/mid);
            }

            if(totalHour <= h){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};