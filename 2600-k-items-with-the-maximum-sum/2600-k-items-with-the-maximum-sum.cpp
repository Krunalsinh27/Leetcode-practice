class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        int takeOnes = min(numOnes, k);

        sum += takeOnes;
        k -= takeOnes;

        int takeZeros = min(numZeros, k);
        
        k -= takeZeros;

        sum -= k;

        return sum;
    }
};