class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            bool greaterThanLeft = true;

            for(int j=0; j<i; j++){
                if(nums[i] <= nums[j]){
                    greaterThanLeft = false;
                    break;
                }
            }

            bool greaterThanRight = true;
            if(!greaterThanLeft){
                for(int j=i+1; j<nums.size(); j++){
                    if(nums[i] <= nums[j]){
                        greaterThanRight = false;
                        break;
                    }
                }
            }

            if(greaterThanLeft || greaterThanRight){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};