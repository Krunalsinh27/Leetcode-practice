class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }

        unordered_set<int>numSet;

        for(int num : nums){
            numSet.insert(num);
        }

        int longestSub = 1;

        for(int num : numSet){
            if(numSet.count(num - 1)){
                continue;
            }else{
                int currentNum = num;
                int currentSub = 1;

                while(numSet.count(currentNum + 1)){
                    currentSub++;
                    currentNum++;
                }

                longestSub = max(currentSub, longestSub);
            }
        }
        return longestSub;
    }
};