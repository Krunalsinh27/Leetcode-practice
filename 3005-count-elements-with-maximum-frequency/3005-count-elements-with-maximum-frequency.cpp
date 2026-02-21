class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> arr(101);
        int sumFreq = 0;
        int maxFreq = 0;

        for(int num : nums){
            arr[num]++;
            int currFreq = arr[num];

            if(currFreq > maxFreq){
                maxFreq = currFreq;
                sumFreq = currFreq;
            }else if(currFreq == maxFreq){
                sumFreq += currFreq;
            }
        }
        return sumFreq;
    }
};