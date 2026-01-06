class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pivotInx = rand()%nums.size();
        int pivot = nums[pivotInx];

        vector<int> leftArr;
        vector<int> midArr;
        vector<int> rightArr;

        for(int val : nums){
            if(val > pivot){
                leftArr.push_back(val);
            }else if(val < pivot){
                rightArr.push_back(val);
            }else{
                midArr.push_back(val);
            }
        }
        if(k <= leftArr.size()){
            return findKthLargest(leftArr, k);
        }
        if(leftArr.size() + midArr.size() < k){
            return findKthLargest(rightArr, k-leftArr.size()-midArr.size());
        }
        return pivot;
    }
};