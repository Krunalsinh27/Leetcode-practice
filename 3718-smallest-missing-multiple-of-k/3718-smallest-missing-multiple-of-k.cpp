class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int num : nums){
            st.insert(num);
        }

        int multiple = k;

        while(st.count(multiple)){
            multiple += k;
        }
        return multiple;
    }
};