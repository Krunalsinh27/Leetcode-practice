class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int>st;
        int ans = 0;

        for(int num : nums){
            if(st.count(num)){
                ans = ans ^ num;
            }else{
                st.insert(num);
            }
        }
        return ans;
    }
};