class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int curr_max = INT_MIN;

        for(int i=0; i<k; i++){
            pq.push({nums[i][0], i, 0});
            curr_max = max(curr_max, nums[i][0]);
        }
        int range_start = 0, range_end = INT_MAX;

        while(true){
            auto top = pq.top();
            pq.pop();

            int curr_min = top[0];
            int list_idx = top[1];
            int elem_idx = top[2];

            if(curr_max - curr_min < range_end - range_start){
                range_start = curr_min;
                range_end = curr_max;
            }

            if(elem_idx + 1 < nums[list_idx].size()){
                int next_val = nums[list_idx][elem_idx + 1];
                pq.push({next_val, list_idx, elem_idx+1});
                curr_max = max(curr_max, next_val);
            }else{
                break;
            }
        }
        return {range_start, range_end};
    }
};