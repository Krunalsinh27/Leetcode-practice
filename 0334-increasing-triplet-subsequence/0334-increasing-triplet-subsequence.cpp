class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int sec = INT_MAX;

        for(int num : nums){
            if(num <= first){
                first = num;
            }else if(num <= sec){
                sec = num;
            }else{
                return true;
            }
        }
        return false;
    }
};