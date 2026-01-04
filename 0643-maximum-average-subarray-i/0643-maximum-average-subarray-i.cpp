class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum=0;

        for(int i=0; i<k; i++){
            sum += nums[i];
        }

        double avg = sum/k;
        int j=0;
        for(int i=k; i<n; i++){
            sum += nums[i];
            sum -= nums[j];
            j++;
            double newAvg = sum/k;
            avg = max(avg, newAvg);
        }
        return avg;
    }
};