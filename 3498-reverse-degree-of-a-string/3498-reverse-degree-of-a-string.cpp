class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            int val = 26 - (s[i] - 'a');
            sum += val*(i+1);
        }
        return sum;
    }
};